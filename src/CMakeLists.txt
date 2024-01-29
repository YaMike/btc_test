add_library(OrderBook OrderBook.cpp Snapshot.cpp Update.cpp)

target_include_directories(OrderBook PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)