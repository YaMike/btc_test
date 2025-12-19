#include <map>
#include <string>
#include <iostream>
#include <Update.hpp>
#include <Snapshot.hpp>

#ifndef _ORDER_BOOK_HPP_
#define _ORDER_BOOK_HPP_

class OrderBook {
public:
    void processSnapshot(const Snapshot& snapshot);
    void processUpdate(const Update& update);

    double getBestBid() const;
    double getBestAsk() const;

    friend std::ostream& operator<<(std::ostream& os, const OrderBook& orderBook);

private:
    void processSide(const std::vector<std::pair<double, double>>& prices, std::map<double, double>& side);

    /* data storage - maps maintain sorted order automatically */
    std::map<double, double> bids;  // sorted ascending, use rbegin() for best bid
    std::map<double, double> asks;  // sorted ascending, use begin() for best ask
};

#endif /* _ORDER_BOOK_HPP */