#include <vector>
#include <iostream>

#ifndef _SNAPSHOT_HPP_
#define _SNAPSHOT_HPP_

struct Snapshot {
    std::vector<std::pair<double, double>> bids;
    std::vector<std::pair<double, double>> asks;

    friend std::ostream& operator<<(std::ostream& os, const Snapshot& snapshot);
};

#endif /* _SNAPSHOT_HPP_ */