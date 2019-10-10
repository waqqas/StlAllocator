#include "benchmark/benchmark.h"

#include "SecurityHasher.h"

static void BM_security_map(benchmark::State &state)
{
  security_map map;
  int32_t key = 0;
  int64_t value = 0;
  for (auto _ : state)
  {
    map.insert({key, value});
    ++key;
  }
}

BENCHMARK(BM_security_map);

BENCHMARK_MAIN();
