# Uphold Coding Challenge

## Overview
This solution pads groups of digits in a string with leading zeros to meet a minimum width, while leaving longer digit groups and all non-digit characters unchanged.

**Final Approach**: Clean, single-pass string builder

## Key Improvements
- Simplified from multiple experimental versions to **one clean and efficient** solution
- Fixed critical edge cases (especially digit groups longer than target width)
- Single-pass implementation for better readability and performance
- No unnecessary complexity (removed linked lists, repeated insertions, etc.)
- Strong focus on correctness and maintainability

## Time and Space Complexity

- **Time Complexity**: **O(n)**  
  Where `n` is the length of the input string. The algorithm makes a single pass over the string, processing each character exactly once.

- **Space Complexity**: **O(n)**  
  We create an output string that is roughly the same size as the input (plus a small number of padding zeros in the worst case). We use `reserve()` to minimize reallocations.

This solution is efficient and predictable, with no hidden costs from heavy operations or external algorithms.

## Why This Design?
- Single pass through the string
- Minimal allocations using `reserve()`
- Avoids expensive in-place string insertions
- Robust against all major edge cases:
  - Groups longer than `width` (e.g. `"abc12345def", 3` → unchanged)
  - Empty strings
  - No digits present
  - Zero width
  - Mixed alphanumeric content
 
## External Libraries
Google Test and Google Benchmark are used **only** for testing and performance measurement. They have **no impact** on the core solution’s time or space complexity.

## Tests
Full test suite in `googleTest.cpp` covering:
- Core functionality
- Edge cases recommended by recruiter
- Longer digit groups, empty input, trailing non-digits, etc.

## Benchmarks
Performance benchmarks in `googleBenchMark.cpp` for both small and large inputs.

## Build & Run
```bash
# 1. Build the project
mkdir build && cd build
cmake ..
cmake --build .

# 2. Run Unit Tests
./tests

# 3. Run Benchmarks (optional)
./benchmarks
