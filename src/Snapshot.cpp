#include <Snapshot.hpp>

std::ostream& operator<<(std::ostream& os, const Snapshot& snapshot) {
    os << "\nBids: ";
    for (const auto& entry : snapshot.bids) {
        os << "[" << entry.first << ", " << entry.second << "] ";
    }
    os << "\nAsks: ";
    for (const auto& entry : snapshot.asks) {
        os << "[" << entry.first << ", " << entry.second << "] ";
    }
    return os;
}