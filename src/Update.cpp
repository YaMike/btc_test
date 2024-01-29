#include <Update.hpp>

Update::Update(std::string event, std::string symbol,
       std::unordered_map<std::string, std::vector<std::pair<double, double>>> priceQty) : event(std::move(event)), symbol(std::move(symbol))
{
    for (const auto &entry : priceQty["b"])
    {
        this->bids.push_back({entry.first, entry.second});
    }
    for (const auto &entry : priceQty["a"])
    {
        this->asks.push_back({entry.first, entry.second});
    }
}

std::ostream &operator<<(std::ostream &os, const Update &update)
{
    os << "\nEvent: " << update.event << ", Symbol: " << update.symbol << "\nBids: ";
    for (const auto &priceQty : update.bids)
    {
        os << "[" << priceQty.first << ", " << priceQty.second << "] ";
    }
    os << "\nAsks: ";
    for (const auto &priceQty : update.asks)
    {
        os << "[" << priceQty.first << ", " << priceQty.second << "] ";
    }
    return os;
}