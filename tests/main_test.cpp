#include <gtest/gtest.h>
#include "OrderBook.hpp"

TEST(OrderBookTest, ProcessSnapshotAndUpdates) {

    OrderBook orderBook;

    Snapshot snapshot = {
        .bids={{0.0024, 14.70000000}, {0.0022, 6.40000000}, {0.0020, 9.70000000}},
        .asks={{0.0024, 14.90000000}, {0.0026, 3.60000000}, {0.0028, 1.00000000}}
    };

    orderBook.processSnapshot(snapshot);
    EXPECT_EQ(orderBook.getBestBid(), 0.0024);
    EXPECT_EQ(orderBook.getBestAsk(), 0.0024);

    std::vector<Update> updates = {
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 10.0  }}}, {"a", {{0.0026, 100.0 }}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 8.0   }}}, {"a", {{0.0028, 0.0   }}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 0.0   }}}, {"a", {{0.0026, 15.0}, {0.0027, 5.0} }}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 100.0 }}}, {"a", {{0.0026, 0.0}, {0.0027, 5.0}  }}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 0.0   }}}, {"a", {{0.0026, 15.0}, {0.0024, 0.0} }}}}
    };

    for (const auto& update : updates) {
        orderBook.processUpdate(update);
    }
    EXPECT_EQ(orderBook.getBestBid(), 0.0022);
    EXPECT_EQ(orderBook.getBestAsk(), 0.0026);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
