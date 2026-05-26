# Uphold Coding Challenge 

## Overview
This solution pads groups of digits in a string with leading zeros to meet a minimum width, while leaving longer digit groups and all non-digit characters unchanged.

## Key Improvements
- Switched to two-pass approach for exact memory allocation (no reallocations)
- Fixed all critical edge cases
- Strong focus on memory efficiency and predictability

## Time and Space Complexity
- **Time Complexity**: **O(n)** (two passes over the string)
- **Space Complexity**: **O(n)** with exact allocation (no overallocation or reallocations)

## Why This Design?
- First pass calculates exact number of padding zeros needed
- Second pass allocates final string once and writes sequentially
- Zero risk of hidden reallocations
- Excellent cache behavior and memory predictability

## External Libraries
Google Test and Google Benchmark are used only for testing and performance measurement.

## Tests & Benchmarks
- Full test suite in `googleTest.cpp`
- Benchmarks in `googleBenchMark.cpp`

## Build & Run

```bash
mkdir build && cd build
cmake ..
cmake --build .

./tests          # Run unit tests
./benchmarks     # Run benchmarks
