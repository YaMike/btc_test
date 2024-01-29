#include <OrderBook.hpp>

void OrderBook::processSnapshot(const Snapshot &snapshot)
{
    processSide(snapshot.bids, bids);
    processSide(snapshot.asks, asks);

    updateBest();
}

void OrderBook::processUpdate(const Update &update)
{
    processSide(update.bids, bids);
    processSide(update.asks, asks);

    updateBest();
}

double OrderBook::getBestBid() const
{
    return max_bids.empty() ? 0.0 : max_bids.top();
}

double OrderBook::getBestAsk() const
{
    return min_asks.empty() ? 0.0 : min_asks.top();
}

void OrderBook::processSide(const std::vector<std::pair<double, double>> &prices, std::unordered_map<double, double> &side)
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

void OrderBook::updateBest()
{
    max_bids = buildMaxBids(bids);
    min_asks = buildMinAsks(asks);
}

std::priority_queue<double>
OrderBook::buildMaxBids(const std::unordered_map<double, double> &data) const
{
    std::priority_queue<double> maxHeap;

    for (const auto &entry : data)
    {
        maxHeap.push(entry.first);
    }

    return maxHeap;
}

std::priority_queue<double, std::vector<double>, std::greater<double>>
OrderBook::buildMinAsks(const std::unordered_map<double, double> &data) const
{
    std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap;

    for (const auto &entry : data)
    {
        minHeap.push(entry.first);
    }

    return minHeap;
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
    os << "\nOB: Max Bids:";
    std::priority_queue<double> max_bids_copy = orderBook.max_bids;
    while (!max_bids_copy.empty())
    {
        os << "[" << max_bids_copy.top() << "] ";
        max_bids_copy.pop();
    }
    os << "\nOB: Min Asks:";
    std::priority_queue<double, std::vector<double>, std::greater<double>> min_asks_copy = orderBook.min_asks;
    while (!min_asks_copy.empty())
    {
        os << "[" << min_asks_copy.top() << "] ";
        min_asks_copy.pop();
    }
    return os;
};