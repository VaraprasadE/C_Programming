# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -pthread -lm

# Target executables
TARGET = threadInc
NO_THREAD_TARGET = nothreadInc

# Source files
SOURCE = Multi_thread.c

# Default target
all: $(TARGET)

# Build threaded version
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o $(TARGET)

# Build non-threaded version
$(NO_THREAD_TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o $(NO_THREAD_TARGET)

# Build both versions
both: $(TARGET) $(NO_THREAD_TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) $(NO_THREAD_TARGET)

# Force rebuild
rebuild: clean all

.PHONY: all both clean rebuild