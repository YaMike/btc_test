#include <queue>
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
    void processSide(const std::vector<std::pair<double, double>>& prices, std::unordered_map<double, double>& side);
    void updateBest();

    std::priority_queue<double>
    buildMaxBids(const std::unordered_map<double, double>& data) const;

    std::priority_queue<double, std::vector<double>, std::greater<double>>
    buildMinAsks(const std::unordered_map<double, double>& data) const;

    /* data storage */
    std::unordered_map<double, double> bids;
    std::unordered_map<double, double> asks;
    std::priority_queue<double> max_bids;
    std::priority_queue<double, std::vector<double>, std::greater<double>> min_asks;
};

#endif /* _ORDER_BOOK_HPP */