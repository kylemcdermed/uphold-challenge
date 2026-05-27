# Uphold Coding Challenge 

## Overview
This solution pads groups of digits in a string with leading zeros to meet a minimum width, while leaving longer digit groups and all non-digit characters unchanged.

## Overview
This solution pads groups of digits in a string with leading zeros to meet a minimum width, while leaving longer digit groups and all non-digit characters unchanged.

Two-pass exact allocation with direct buffer writing

## Key Improvements
- Two-pass approach for exact memory allocation
- Direct ASCII range checks (`'0'` to `'9'`)
- Uses `resize()` + `memset` + `memcpy` for efficient buffer writing
- Strong focus on memory predictability and performance

## Time and Space Complexity
- **Time Complexity**: **O(n)** (two passes over the input string)
- **Space Complexity**: **O(n)** with exact allocation (no reallocations or overallocation)

## Why This Design?
- First pass calculates exact padding required
- Second pass writes directly into a pre-sized buffer
- Avoids high-level string operations (`append`, `push_back`, `substr`) 
- Better performance and cache behavior

## External Libraries
Google Test and Google Benchmark are used only for testing and benchmarking.

## Tests & Benchmarks
- Full test coverage in `googleTest.cpp`
- Benchmarks in `googleBenchMark.cpp`

## Build & Run

```bash
mkdir build && cd build
cmake ..
cmake --build .

./tests         
./benchmarks

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
