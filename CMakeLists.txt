cmake_minimum_required(VERSION 3.14)
project(MyTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# ─── Google Test ────────────────────────────────────────────────────────────
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# ─── Google Benchmark ───────────────────────────────────────────────────────
FetchContent_Declare(
  googlebenchmark
  URL https://github.com/google/benchmark/archive/refs/heads/main.zip
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googlebenchmark)

# ─── Tests executable ───────────────────────────────────────────────────────
enable_testing()

add_executable(tests
    solution1.cpp
    solution2.cpp
    solution3.cpp
    solution4.cpp
    googleTest.cpp
)
target_link_libraries(tests
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(tests)

# ─── Benchmark executable ───────────────────────────────────────────────────
add_executable(benchmarks
    solution1.cpp
    solution2.cpp
    solution3.cpp
    solution4.cpp
    googleBenchMark.cpp
)
target_link_libraries(benchmarks
    benchmark::benchmark
)