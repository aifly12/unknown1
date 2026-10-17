NDK      ?= /opt/ndk/android-ndk-r29
TOOLCHAIN := $(NDK)/toolchains/llvm/prebuilt/linux-x86_64
CC       := $(TOOLCHAIN)/bin/aarch64-linux-android30-clang
CFLAGS   := -O2 -Wall -Wextra
TARGET   := perf_test

all: $(TARGET)

$(TARGET): perf_test.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: all clean
