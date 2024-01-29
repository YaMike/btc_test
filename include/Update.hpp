#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#ifndef _UPDATE_HPP_
#define _UPDATE_HPP_

struct Update {
    std::string event;
    std::string symbol;
    std::vector<std::pair<double, double>> bids;
    std::vector<std::pair<double, double>> asks;
    
    Update(std::string event, std::string symbol,
           std::unordered_map<std::string,
           std::vector<std::pair<double, double>>> priceQty);

    friend std::ostream& operator<<(std::ostream& os, const Update& update);
};

#endif /* _UPDATE_HPP_ */