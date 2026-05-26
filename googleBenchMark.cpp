#include <benchmark/benchmark.h>
#include <string>
#include "solution.cpp"

using namespace std;

// Small inputs
static void BM_PadDigitGroups_Small(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(padDigitGroups("James Bond 7", 3));
        benchmark::DoNotOptimize(padDigitGroups("PI=3.14", 2));
        benchmark::DoNotOptimize(padDigitGroups("It's 3:13pm", 2));
        benchmark::DoNotOptimize(padDigitGroups("It's 12:13pm", 2));
        benchmark::DoNotOptimize(padDigitGroups("99UR1337", 6));
    }
}

// Large stress test
static void BM_PadDigitGroups_Large(benchmark::State& state) {
    string large = "";
    for (int i = 0; i < 1000; ++i) {
        large += "Word 12345 AnotherWord 9 ";
    }
    for (auto _ : state) {
        benchmark::DoNotOptimize(padDigitGroups(large, 8));
    }
}

BENCHMARK(BM_PadDigitGroups_Small);
BENCHMARK(BM_PadDigitGroups_Large);
BENCHMARK_MAIN();
