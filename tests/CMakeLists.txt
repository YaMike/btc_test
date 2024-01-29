include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

# find_package(benchmark REQUIRED)
# Add Google Benchmark library
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Enable testing of the benchmark library.")
add_subdirectory(benchmark)

add_executable(MainTest main_test.cpp)
target_link_libraries(MainTest GTest::gtest_main OrderBook)

set(JUNIT_XML_OUTPUT_FILE "${CMAKE_BINARY_DIR}/test_results.xml")
add_custom_target(RunMainTest
                  COMMAND MainTest --gtest_output=xml:${JUNIT_XML_OUTPUT_FILE}
                  DEPENDS MainTest
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests)

add_executable(BenchmarkTest benchmark_test.cpp)
target_link_libraries(BenchmarkTest benchmark OrderBook)                  

add_custom_target(RunBenchmarkTest
                  COMMAND BenchmarkTest
                  DEPENDS BenchmarkTest
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests)

gtest_discover_tests(MainTest)