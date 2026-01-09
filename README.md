# RSA Implementation in C++

A simple RSA encryption/decryption implementation for the Cryptography course at GJU (German Jordanian University).

## Prerequisites

- C++ compiler (g++)
- NTL library (Number Theory Library)
- GMP library (GNU Multiple Precision Arithmetic Library)

## Installation

Install the required libraries:
```bash
sudo apt-get install libntl-dev libgmp-dev
```

## Compilation & Usage

### Main RSA Program
Encrypt/decrypt integers or sentences with automatic or manual key generation:
```bash
make rsa
```

### Simple Example (from textbook)
Basic RSA demonstration with manual parameter selection:
```bash
make simple
```

### Test Program
NTL library test:
```bash
make test
```

## Features

- Generate random prime numbers or choose your own
- Support for both integer and text encryption/decryption
- Uses NTL library for large number arithmetic
- Interactive command-line interface

## Clean Up

```bash
make clean
```
