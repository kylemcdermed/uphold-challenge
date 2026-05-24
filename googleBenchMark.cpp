#include <benchmark/benchmark.h>
#include <string>
#include "solution1.h"
#include "solution2.h"
#include "solution3.h"
#include "solution4.h"

using namespace std;

// ─── Small inputs (same as your test cases) ───────────────────────────────

static void BM_Solution1_Small(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(solution1("James Bond 7", 3));
        benchmark::DoNotOptimize(solution1("PI=3.14", 2));
        benchmark::DoNotOptimize(solution1("It's 3:13pm", 2));
        benchmark::DoNotOptimize(solution1("It's 12:13pm", 2));
        benchmark::DoNotOptimize(solution1("99UR1337", 6));
    }
}

static void BM_Solution2_Small(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(solution2("James Bond 7", 3));
        benchmark::DoNotOptimize(solution2("PI=3.14", 2));
        benchmark::DoNotOptimize(solution2("It's 3:13pm", 2));
        benchmark::DoNotOptimize(solution2("It's 12:13pm", 2));
        benchmark::DoNotOptimize(solution2("99UR1337", 6));
    }
}

static void BM_Solution3_Small(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(solution3("James Bond 7", 3));
        benchmark::DoNotOptimize(solution3("PI=3.14", 2));
        benchmark::DoNotOptimize(solution3("It's 3:13pm", 2));
        benchmark::DoNotOptimize(solution3("It's 12:13pm", 2));
        benchmark::DoNotOptimize(solution3("99UR1337", 6));
    }
}

static void BM_Solution4_Small(benchmark::State& state) {
    for (auto _ : state) {
        SLL s1; benchmark::DoNotOptimize(s1.upholdChallenge("James Bond 7", 3));
        SLL s2; benchmark::DoNotOptimize(s2.upholdChallenge("PI=3.14", 2));
        SLL s3; benchmark::DoNotOptimize(s3.upholdChallenge("It's 3:13pm", 2));
        SLL s4; benchmark::DoNotOptimize(s4.upholdChallenge("It's 12:13pm", 2));
        SLL s5; benchmark::DoNotOptimize(s5.upholdChallenge("99UR1337", 6));
    }
}

// ─── Large stress-test inputs ─────────────────────────────────────────────

static void BM_Solution1_Large(benchmark::State& state) {
    string large = "";
    for (int i = 0; i < 1000; ++i) large += "Word 12345 AnotherWord 9 ";
    for (auto _ : state) {
        benchmark::DoNotOptimize(solution1(large, 8));
    }
}

static void BM_Solution2_Large(benchmark::State& state) {
    string large = "";
    for (int i = 0; i < 1000; ++i) large += "Word 12345 AnotherWord 9 ";
    for (auto _ : state) {
        benchmark::DoNotOptimize(solution2(large, 8));
    }
}

static void BM_Solution3_Large(benchmark::State& state) {
    string large = "";
    for (int i = 0; i < 1000; ++i) large += "Word 12345 AnotherWord 9 ";
    for (auto _ : state) {
        benchmark::DoNotOptimize(solution3(large, 8));
    }
}

static void BM_Solution4_Large(benchmark::State& state) {
    string large = "";
    for (int i = 0; i < 1000; ++i) large += "Word 12345 AnotherWord 9 ";
    for (auto _ : state) {
        SLL s;
        benchmark::DoNotOptimize(s.upholdChallenge(large, 8));
    }
}

// ─── Register all benchmarks ──────────────────────────────────────────────

BENCHMARK(BM_Solution1_Small);
BENCHMARK(BM_Solution2_Small);
BENCHMARK(BM_Solution3_Small);
BENCHMARK(BM_Solution4_Small);
BENCHMARK(BM_Solution1_Large);
BENCHMARK(BM_Solution2_Large);
BENCHMARK(BM_Solution3_Large);
BENCHMARK(BM_Solution4_Large);

BENCHMARK_MAIN();