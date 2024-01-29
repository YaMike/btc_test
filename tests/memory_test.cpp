
#include <gtest/gtest.h>
#include "OrderBook.hpp"
#include <fstream>
#include <string>
#include <sstream>

long getMemoryConsumptionKB() {
    /*
     * Utilize /proc/self/statm. From man pages:
            /proc/[pid]/statm
              Provides information about memory usage, measured in pages.  The columns are:

                  size       (1) total program size
                             (same as VmSize in /proc/[pid]/status)
                  resident   (2) resident set size
                             (inaccurate; same as VmRSS in /proc/[pid]/status)
                  shared     (3) number of resident shared pages
                             (i.e., backed by a file)
                             (inaccurate; same as RssFile+RssShmem in
                             /proc/[pid]/status)
                  text       (4) text (code)
                  lib        (5) library (unused since Linux 2.6; always 0)
                  data       (6) data + stack
                  dt         (7) dirty pages (unused since Linux 2.6; always 0)
    */
    long result = 0;
    std::ifstream stat_stream("/proc/self/statm");

    if (stat_stream) {
        std::string line;
        std::getline(stat_stream, line);

        std::istringstream iss(line);
        iss >> result; // Get the first value, which represents the total program size in pages

        // Convert pages to kilobytes
        result *= static_cast<long>(getpagesize()) / 1024;
    }

    return result;
}

TEST(OrderBookTest, ProcessSnapshotAndUpdates) {

    Snapshot snapshot = {
        .bids={{0.0024, 14.70000000}, {0.0022, 6.40000000}, {0.0020, 9.70000000}},
        .asks={{0.0024, 14.90000000}, {0.0026, 3.60000000}, {0.0028, 1.00000000}}
    };

    std::vector<Update> updates = {
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 10.0  }}}, {"a", {{0.0026, 100.0 }}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 8.0   }}}, {"a", {{0.0028, 0.0   }}}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0024, 0.0   }}}, {"a", {{0.0026, 15.0}, {0.0027, 5.0} }}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 100.0 }}}, {"a", {{0.0026, 0.0}, {0.0027, 5.0}  }}}},
        {"depthUpdate", "BNBBTC", {{"b", {{0.0025, 0.0   }}}, {"a", {{0.0026, 15.0}, {0.0024, 0.0} }}}}
    };

    long initialMemory = getMemoryConsumptionKB();
    OrderBook orderBook;
    orderBook.processSnapshot(snapshot);
    long afterSnapshot = getMemoryConsumptionKB();
    for (const auto& update : updates) {
        orderBook.processUpdate(update);
    }
    long afterUpdates = getMemoryConsumptionKB();
    std::cout << "initial memory: " << initialMemory << std::endl;
    std::cout << "after snapshot: " << afterSnapshot << std::endl;
    std::cout << "after updates:  " << afterUpdates  << std::endl;
    EXPECT_LE(afterSnapshot - initialMemory, 100);
    EXPECT_LE(afterUpdates - afterSnapshot, 100);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
