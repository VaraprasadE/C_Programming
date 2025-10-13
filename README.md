# C Programming Examples

This repository contains various C programming examples and exercises, demonstrating different concepts and techniques.

## Projects

### C-Program
A collection of basic C programs including:
- **Main.c**: Main program that demonstrates prime number checking and odd/even number detection
- **isprime.c**: Implementation of prime number checking algorithm
- **isoddeven.c**: Implementation of odd/even number detection
- **peo.h**: Header file containing function declarations
- **Makefile**: Build configuration for compiling the project

#### Building and Running
```bash
cd C-Program
make
./program
```

#### Cleaning Build Files
```bash
make clean
```

### Multi-Threading
Threading examples and performance testing tools:
- **Multi_thread.c**: Multi-threaded prime number finder with performance comparison between threaded and non-threaded implementations

#### Compilation
```bash
cd Multi-Threading
gcc -pthread -o threadInc Multi_thread.c -lm
```

#### Usage
```bash
# Default: 10 threads, find first 10,000,000 primes
./threadInc

# Custom number of primes to find
./threadInc 5000000

# Custom threads and primes
./threadInc 5 5000000
```

## Features

- **Prime Number Detection**: Efficient algorithms for checking if numbers are prime
- **Multi-threading**: Performance comparison between single-threaded and multi-threaded approaches
- **Modular Design**: Well-organized code with header files and separate compilation units

## Requirements

- GCC compiler
- POSIX threads library (pthread)
- Math library (libm)

## Contributing

Feel free to add more C programming examples and improve existing code!