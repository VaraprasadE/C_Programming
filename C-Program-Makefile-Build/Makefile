# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Target executable
TARGET = program

# Source files
SOURCES = Main.c isprime.c isoddeven.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = peo.h

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f *.o $(TARGET)

# Force rebuild
rebuild: clean all

.PHONY: all clean rebuild