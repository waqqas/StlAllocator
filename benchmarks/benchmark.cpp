#include "benchmark/benchmark.h"

#include "SecurityHasher.h"
#include <iostream>

using standard_map = std::unordered_map<int32_t, uint64_t>;


template <class Map> 
void BM_insert(benchmark::State &state)
{
  Map map;
  int32_t key = 0;
  int64_t value = 0;
  for (auto _ : state)
  {
    map.insert({key, value});
    ++key;
  }
}

template <class Map> 
void BM_find(benchmark::State &state)
{
  Map map;
  int32_t key = 0;
  int64_t value = 0;
  size_t size = state.range(0);
  // std::cout << "size: " << size << std::endl;
  for(size_t key = 0; key < size; ++key)
  {
    map.insert({key,value});
  }

  key = 0;
  for (auto _ : state)
  {
    // std::cout << "key: " << key << std::endl;
    benchmark::DoNotOptimize(map.find(key));
    ++key;
    key %= size;
  }
}


BENCHMARK_TEMPLATE1(BM_insert, security_map);
BENCHMARK_TEMPLATE1(BM_insert, standard_map);


BENCHMARK_TEMPLATE1(BM_find, security_map)->Range(1 << 8, 1 << 18);
BENCHMARK_TEMPLATE1(BM_find, standard_map)->Range(1 << 8, 1 << 18);
BENCHMARK_MAIN();
