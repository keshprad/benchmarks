// Benchmark std::accumulate

#include <algorithm>
#include <benchmark/benchmark.h>
#include <cstdlib>
#include <numeric>
#include <vector>

static void accumulate_bench(benchmark::State &s) {
  // set up num elements (2^10)
  auto N = 1 << s.range(0);

  // Create vector of random numbers
  std::vector<int> v(N);
  std::generate(begin(v), end(v), [] { return rand() % 100; });

  // Variable for result
  int result = 0;

  // Main timing loop
  for (auto _ : s) {
    benchmark::DoNotOptimize(result = std::accumulate(begin(v), end(v), 0));
  }
}
BENCHMARK(accumulate_bench)->DenseRange(10, 12)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
