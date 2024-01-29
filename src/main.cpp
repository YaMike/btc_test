#include <OrderBook.hpp>

/* file main.cpp */
int main() {
    OrderBook orderBook;
    std::cout << "Empty order book:" << std::endl;
    std::cout << "Best Bid: " << orderBook.getBestBid() << std::endl;
    std::cout << "Best Ask: " << orderBook.getBestAsk() << std::endl;

    Snapshot snapshot = {
        .bids={{0.0024, 14.70000000}, {0.0022, 6.40000000}, {0.0020, 9.70000000}},
        .asks={{0.0024, 14.90000000}, {0.0026, 3.60000000}, {0.0028, 1.00000000}}
    };

    std::cout << "\nAdding snapshot: " << snapshot << std::endl;
    orderBook.processSnapshot(snapshot);
    std::cout << "Order book: " << orderBook << std::endl;
    std::cout << "Best Bid: " << orderBook.getBestBid() << std::endl;
    std::cout << "Best Ask: " << orderBook.getBestAsk() << std::endl;

    std::vector<Update> updates = {
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 10.0  }}}, {"a", {{0.0026, 100.0 }}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 8.0   }}}, {"a", {{0.0028, 0.0   }}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 0.0   }}}, {"a", {{0.0026, 15.0}, {0.0027, 5.0} }}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 100.0 }}}, {"a", {{0.0026, 0.0}, {0.0027, 5.0}  }}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 0.0   }}}, {"a", {{0.0026, 15.0}, {0.0024, 0.0} }}}}
    };

    for (const auto& update : updates) {
        std::cout << "\nAdding update: " << update << std::endl;
        orderBook.processUpdate(update);
        std::cout << "Order book:" << orderBook << std::endl;
        std::cout << "Best Bid: " << orderBook.getBestBid() << std::endl;
        std::cout << "Best Ask: " << orderBook.getBestAsk() << std::endl;
    }

    return 0;
}
