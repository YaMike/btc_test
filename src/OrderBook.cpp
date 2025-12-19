#include <OrderBook.hpp>

void OrderBook::processSnapshot(const Snapshot &snapshot)
{
    processSide(snapshot.bids, bids);
    processSide(snapshot.asks, asks);
}

void OrderBook::processUpdate(const Update &update)
{
    processSide(update.bids, bids);
    processSide(update.asks, asks);
}

double OrderBook::getBestBid() const
{
    // std::map is sorted ascending, so rbegin() gives the highest bid
    return bids.empty() ? 0.0 : bids.rbegin()->first;
}

double OrderBook::getBestAsk() const
{
    // std::map is sorted ascending, so begin() gives the lowest ask
    return asks.empty() ? 0.0 : asks.begin()->first;
}

void OrderBook::processSide(const std::vector<std::pair<double, double>> &prices, std::map<double, double> &side)
{
    for (const auto &priceQty : prices)
    {
        auto [price, quantity] = priceQty;

        if (quantity == 0.0)
        {
            side.erase(price);
        }
        else
        {
            side[price] = quantity;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const OrderBook &orderBook)
{
    os << "\nOB: Bids: ";
    for (const auto &entry : orderBook.bids)
    {
        os << "[" << entry.first << ", " << entry.second << "] ";
    }
    os << "\nOB: Asks: ";
    for (const auto &entry : orderBook.asks)
    {
        os << "[" << entry.first << ", " << entry.second << "] ";
    }
    return os;
};