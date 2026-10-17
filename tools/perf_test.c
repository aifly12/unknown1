#include <linux/perf_event.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

static int test_one(const char *name, uint64_t id) {
    struct perf_event_attr attr;
    memset(&attr, 0, sizeof(attr));
    attr.type = PERF_TYPE_TRACEPOINT;
    attr.size = sizeof(attr);
    attr.config = id;
    attr.disabled = 1;

    int fd = (int)syscall(__NR_perf_event_open, &attr, 0, -1, -1, 0);
    if (fd < 0) {
        printf("%s: FAILED errno=%d (%s)\n", name, errno, strerror(errno));
        return -1;
    }
    printf("%s: OK fd=%d\n", name, fd);
    close(fd);
    return 0;
}

int main(void) {
    printf("uid=%d euid=%d\n", getuid(), geteuid());
    test_one("mm_page_free (239)", 239);
    test_one("mm_page_alloc (241)", 241);
    return 0;
}
