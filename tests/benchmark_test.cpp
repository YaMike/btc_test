#include <benchmark/benchmark.h>
#include "OrderBook.hpp"
#include <vector>

static void BM_ProcessUpdate(benchmark::State& state) {
    OrderBook orderBook;

    Update update = {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 10.0  }}}, {"a", {{0.0026, 100.0 }}}}};

    for (auto _ : state) {
        orderBook.processUpdate(update);
    }
}

BENCHMARK(BM_ProcessUpdate);

BENCHMARK_MAIN();
