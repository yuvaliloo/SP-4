# MyContainer with Custom Iterators

This project implements a dynamic container class `MyContainer<T>` in C++ that supports various custom iterators with different traversal orders. The container works with any comparable type (e.g., `int`, `double`, `std::string`) and provides dynamic addition/removal of elements.

## Features

- ✅ Add and remove elements (`add`, `remove`)
- ✅ Dynamic resizing
- ✅ Supports multiple custom iterators:
  - `AscendingOrder`: sorted from smallest to largest
  - `DescendingOrder`: sorted from largest to smallest
  - `SideCrossOrder`: smallest, largest, next-smallest, next-largest, ...
  - `ReverseOrder`: original order, reversed
  - `Order`: original insertion order
  - `MiddleOutOrder`: middle, left, right, left, right...

## Usage

To build and run:

```bash
make main     # Build the example main program
make Test     # Build and run the test suite
make valgrind # Run tests with Valgrind
make clean    # Clean up build artifacts
