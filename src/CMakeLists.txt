add_library(OrderBook OrderBook.cpp Snapshot.cpp Update.cpp)

target_include_directories(OrderBook PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(Main main.cpp)
target_link_libraries(Main OrderBook)

add_custom_target(RunMain
                  COMMAND Main 
                  DEPENDS Main
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests)