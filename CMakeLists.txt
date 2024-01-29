cmake_minimum_required(VERSION 3.10)

project(OrderBook)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Build type: Release")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Build type: Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
endif()

add_subdirectory(src)
add_subdirectory(tests)
