#include <benchmark/benchmark.h>
#include "OrderBook.hpp"
#include <vector>

static void BM_ProcessUpdate(benchmark::State &state)
{
    OrderBook orderBook;

    Update update = {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 10.0}}}, {"a", {{0.0026, 100.0}}}}};
    std::vector<Update> updates = {
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 10.0}}}, {"a", {{0.0026, 100.0}}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 8.0}}}, {"a", {{0.0028, 0.0}}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 0.0}}}, {"a", {{0.0026, 15.0}, {0.0027, 5.0}}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 100.0}}}, {"a", {{0.0026, 0.0}, {0.0027, 5.0}}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 0.0}}}, {"a", {{0.0026, 15.0}, {0.0024, 0.0}}}}}};
    for (auto _ : state)
    {
        for (auto update : updates)
        {
            orderBook.processUpdate(update);
        }
    }
}

BENCHMARK(BM_ProcessUpdate);

BENCHMARK_MAIN();
