# Cryptography Factorization Examples

This repository contains two small C++ programs that demonstrate simple factorization techniques using the C++ Standard Library's `std::gcd` function.

- **Source.cpp** – Interactive program that attempts to find non-trivial factors of a user-supplied integer. It uses XOR operations and the greatest common divisor to search for factors and prints any unique factors found.
- **Source1.cpp** – A similar program that prints factors as they are discovered. (Note: this file appears to be incomplete and may not compile.)

## Building

Compile each program with `g++`:

```bash
# Build the first program
g++ Source.cpp -o factor

# Build the second program
g++ Source1.cpp -o factor1
```

## Running

After compiling, run the executables directly. For example, to use `factor`:

```bash
./factor
```

It will prompt for a number to factor and will display any factors found. Enter `0` to exit. Similarly, you can run `./factor1` after compiling `Source1.cpp`.

