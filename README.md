# btc_test

## prerequisites

Needs:
* google test framework (downloaded by cmake at first execution)
* google benchmark framework (needs manual download - below)

Install benchmarks from google:
```
cd tests
git clone https://github.com/google/benchmark.git
```

## building && main app running && main app testing && benchmark testing 

One-liner to build&run&run_main&run_tests:
* build - compiles static library including all the functionality of OrderBook
* RunMain rule - just runs a main app (main is in the src dir)
* RunMainTest - gtest using similar logic to main app (located in the test dir)
* RunBenchmarkTest - benchmark test (located in the test dir)

```
# run from root level of the repository
cd btc_test

# use sub shell to not to harm existing env
(rm -rf build; cmake -B build . ; cd build; make all; make RunMain; make RunMainTest; make RunBenchmarkTest)
```

Output:
* console output for all apps
* JUnit XML output for gtest tests for smooth integration with Jenkins (BlueOcean view plugin):
```
┌─(18:16:54)─(michael@prime)─(~/Projects/cpp/binance)
└─► find -name *.xml
./build/test_results.xml
┌─(18:17:00)─(michael@prime)─(~/Projects/cpp/binance)
└─► cat `find -name *.xml`
<?xml version="1.0" encoding="UTF-8"?>
<testsuites tests="1" failures="0" disabled="0" errors="0" time="0" timestamp="2024-01-29T16:53:13.054" name="AllTests">
  <testsuite name="OrderBookTest" tests="1" failures="0" disabled="0" skipped="0" errors="0" time="0" timestamp="2024-01-29T16:53:13.054">
    <testcase name="ProcessSnapshotAndUpdates" file="/home/michael/Projects/cpp/binance/tests/main_test.cpp" line="4" status="run" result="completed" time="0" timestamp="2024-01-29T16:53:13.054" classname="OrderBookTest" />
  </testsuite>
</testsuites>
┌─(18:31:08)─(michael@prime)─(~/Projects/cpp/binance)
└─► (rm -rf build; cmake -B build . ; cd build; make all; make RunMain; make RunMainTest; make RunBenchmarkTest)
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Python: /usr/bin/python3.10 (found version "3.10.12") found components: Interpreter 
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE  
-- Failed to find LLVM FileCheck
-- Found Git: /usr/bin/git (found version "2.34.1") 
-- git version: v1.8.3-49-g4682db08 normalized to 1.8.3.49
-- Google Benchmark version: 1.8.3.49
-- Looking for shm_open in rt
-- Looking for shm_open in rt - found
-- Performing Test HAVE_CXX_FLAG_WALL
-- Performing Test HAVE_CXX_FLAG_WALL - Success
-- Performing Test HAVE_CXX_FLAG_WEXTRA
-- Performing Test HAVE_CXX_FLAG_WEXTRA - Success
-- Performing Test HAVE_CXX_FLAG_WSHADOW
-- Performing Test HAVE_CXX_FLAG_WSHADOW - Success
-- Performing Test HAVE_CXX_FLAG_WFLOAT_EQUAL
-- Performing Test HAVE_CXX_FLAG_WFLOAT_EQUAL - Success
-- Performing Test HAVE_CXX_FLAG_WOLD_STYLE_CAST
-- Performing Test HAVE_CXX_FLAG_WOLD_STYLE_CAST - Success
-- Performing Test HAVE_CXX_FLAG_WERROR
-- Performing Test HAVE_CXX_FLAG_WERROR - Success
-- Performing Test HAVE_CXX_FLAG_WSUGGEST_OVERRIDE
-- Performing Test HAVE_CXX_FLAG_WSUGGEST_OVERRIDE - Success
-- Performing Test HAVE_CXX_FLAG_PEDANTIC
-- Performing Test HAVE_CXX_FLAG_PEDANTIC - Success
-- Performing Test HAVE_CXX_FLAG_PEDANTIC_ERRORS
-- Performing Test HAVE_CXX_FLAG_PEDANTIC_ERRORS - Success
-- Performing Test HAVE_CXX_FLAG_WSHORTEN_64_TO_32
-- Performing Test HAVE_CXX_FLAG_WSHORTEN_64_TO_32 - Failed
-- Performing Test HAVE_CXX_FLAG_FSTRICT_ALIASING
-- Performing Test HAVE_CXX_FLAG_FSTRICT_ALIASING - Success
-- Performing Test HAVE_CXX_FLAG_WNO_DEPRECATED_DECLARATIONS
-- Performing Test HAVE_CXX_FLAG_WNO_DEPRECATED_DECLARATIONS - Success
-- Performing Test HAVE_CXX_FLAG_WNO_DEPRECATED
-- Performing Test HAVE_CXX_FLAG_WNO_DEPRECATED - Success
-- Performing Test HAVE_CXX_FLAG_WSTRICT_ALIASING
-- Performing Test HAVE_CXX_FLAG_WSTRICT_ALIASING - Success
-- Performing Test HAVE_CXX_FLAG_WD654
-- Performing Test HAVE_CXX_FLAG_WD654 - Failed
-- Performing Test HAVE_CXX_FLAG_WTHREAD_SAFETY
-- Performing Test HAVE_CXX_FLAG_WTHREAD_SAFETY - Failed
-- Performing Test HAVE_CXX_FLAG_COVERAGE
-- Performing Test HAVE_CXX_FLAG_COVERAGE - Success
-- Compiling and running to test HAVE_STD_REGEX
-- Performing Test HAVE_STD_REGEX -- success
-- Compiling and running to test HAVE_GNU_POSIX_REGEX
-- Performing Test HAVE_GNU_POSIX_REGEX -- failed to compile
-- Compiling and running to test HAVE_POSIX_REGEX
-- Performing Test HAVE_POSIX_REGEX -- success
-- Compiling and running to test HAVE_STEADY_CLOCK
-- Performing Test HAVE_STEADY_CLOCK -- success
-- Compiling and running to test HAVE_PTHREAD_AFFINITY
-- Performing Test HAVE_PTHREAD_AFFINITY -- success
-- Configuring done
-- Generating done
-- Build files have been written to: /home/michael/Projects/cpp/binance/build
[  2%] Building CXX object src/CMakeFiles/OrderBook.dir/OrderBook.cpp.o
[  5%] Building CXX object src/CMakeFiles/OrderBook.dir/Snapshot.cpp.o
[  7%] Building CXX object src/CMakeFiles/OrderBook.dir/Update.cpp.o
[ 10%] Linking CXX static library libOrderBook.a
[ 10%] Built target OrderBook
[ 12%] Building CXX object src/CMakeFiles/Main.dir/main.cpp.o
[ 15%] Linking CXX executable Main
[ 15%] Built target Main
[ 17%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 20%] Linking CXX static library ../../../lib/libgtest.a
[ 20%] Built target gtest
[ 22%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 25%] Linking CXX static library ../../../lib/libgtest_main.a
[ 25%] Built target gtest_main
[ 27%] Building CXX object tests/CMakeFiles/MainTest.dir/main_test.cpp.o
[ 30%] Linking CXX executable MainTest
[ 30%] Built target MainTest
[ 32%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/benchmark.cc.o
[ 35%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/benchmark_api_internal.cc.o
[ 37%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/benchmark_name.cc.o
[ 40%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/benchmark_register.cc.o
[ 42%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/benchmark_runner.cc.o
[ 45%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/check.cc.o
[ 47%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/colorprint.cc.o
[ 50%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/commandlineflags.cc.o
[ 52%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/complexity.cc.o
[ 55%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/console_reporter.cc.o
[ 57%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/counter.cc.o
[ 60%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/csv_reporter.cc.o
[ 62%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/json_reporter.cc.o
[ 65%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/perf_counters.cc.o
[ 67%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/reporter.cc.o
[ 70%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/statistics.cc.o
[ 72%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/string_util.cc.o
[ 75%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/sysinfo.cc.o
[ 77%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark.dir/timers.cc.o
[ 80%] Linking CXX static library libbenchmark.a
[ 80%] Built target benchmark
[ 82%] Building CXX object tests/CMakeFiles/BenchmarkTest.dir/benchmark_test.cpp.o
[ 85%] Linking CXX executable BenchmarkTest
[ 85%] Built target BenchmarkTest
[ 87%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 90%] Linking CXX static library ../../../lib/libgmock.a
[ 90%] Built target gmock
[ 92%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 95%] Linking CXX static library ../../../lib/libgmock_main.a
[ 95%] Built target gmock_main
[ 97%] Building CXX object tests/benchmark/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o
[100%] Linking CXX static library libbenchmark_main.a
[100%] Built target benchmark_main
Consolidate compiler generated dependencies of target OrderBook
[ 66%] Built target OrderBook
Consolidate compiler generated dependencies of target Main
[100%] Built target Main
Empty order book:
Best Bid: 0
Best Ask: 0

Adding snapshot: 
Bids: [0.0024, 14.7] [0.0022, 6.4] [0.002, 9.7] 
Asks: [0.0024, 14.9] [0.0026, 3.6] [0.0028, 1] 
Order book: 
OB: Bids: [0.002, 9.7] [0.0022, 6.4] [0.0024, 14.7] 
OB: Asks: [0.0028, 1] [0.0026, 3.6] [0.0024, 14.9] 
OB: Max Bids:[0.0024] [0.0022] [0.002] 
OB: Min Asks:[0.0024] [0.0026] [0.0028] 
Best Bid: 0.0024
Best Ask: 0.0024

Adding update: 
Event: depthUpdate, Symbol: BNBBTC
Bids: [0.0024, 10] 
Asks: [0.0026, 100] 
Order book:
OB: Bids: [0.002, 9.7] [0.0022, 6.4] [0.0024, 10] 
OB: Asks: [0.0028, 1] [0.0026, 100] [0.0024, 14.9] 
OB: Max Bids:[0.0024] [0.0022] [0.002] 
OB: Min Asks:[0.0024] [0.0026] [0.0028] 
Best Bid: 0.0024
Best Ask: 0.0024

Adding update: 
Event: depthUpdate, Symbol: BNBBTC
Bids: [0.0024, 8] 
Asks: [0.0028, 0] 
Order book:
OB: Bids: [0.002, 9.7] [0.0022, 6.4] [0.0024, 8] 
OB: Asks: [0.0026, 100] [0.0024, 14.9] 
OB: Max Bids:[0.0024] [0.0022] [0.002] 
OB: Min Asks:[0.0024] [0.0026] 
Best Bid: 0.0024
Best Ask: 0.0024

Adding update: 
Event: depthUpdate, Symbol: BNBBTC
Bids: [0.0024, 0] 
Asks: [0.0026, 15] [0.0027, 5] 
Order book:
OB: Bids: [0.002, 9.7] [0.0022, 6.4] 
OB: Asks: [0.0027, 5] [0.0026, 15] [0.0024, 14.9] 
OB: Max Bids:[0.0022] [0.002] 
OB: Min Asks:[0.0024] [0.0026] [0.0027] 
Best Bid: 0.0022
Best Ask: 0.0024

Adding update: 
Event: depthUpdate, Symbol: BNBBTC
Bids: [0.0025, 100] 
Asks: [0.0026, 0] [0.0027, 5] 
Order book:
OB: Bids: [0.0025, 100] [0.002, 9.7] [0.0022, 6.4] 
OB: Asks: [0.0027, 5] [0.0024, 14.9] 
OB: Max Bids:[0.0025] [0.0022] [0.002] 
OB: Min Asks:[0.0024] [0.0027] 
Best Bid: 0.0025
Best Ask: 0.0024

Adding update: 
Event: depthUpdate, Symbol: BNBBTC
Bids: [0.0025, 0] 
Asks: [0.0026, 15] [0.0024, 0] 
Order book:
OB: Bids: [0.002, 9.7] [0.0022, 6.4] 
OB: Asks: [0.0026, 15] [0.0027, 5] 
OB: Max Bids:[0.0022] [0.002] 
OB: Min Asks:[0.0026] [0.0027] 
Best Bid: 0.0022
Best Ask: 0.0026
[100%] Built target RunMain
Consolidate compiler generated dependencies of target gtest
[ 20%] Built target gtest
Consolidate compiler generated dependencies of target gtest_main
[ 40%] Built target gtest_main
[ 80%] Built target OrderBook
Consolidate compiler generated dependencies of target MainTest
[100%] Built target MainTest
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from OrderBookTest
[ RUN      ] OrderBookTest.ProcessSnapshotAndUpdates
[       OK ] OrderBookTest.ProcessSnapshotAndUpdates (0 ms)
[----------] 1 test from OrderBookTest (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
[100%] Built target RunMainTest
Consolidate compiler generated dependencies of target benchmark
[ 76%] Built target benchmark
[ 92%] Built target OrderBook
Consolidate compiler generated dependencies of target BenchmarkTest
[100%] Built target BenchmarkTest
2024-01-29T18:37:09+04:00
Running /home/michael/Projects/cpp/binance/build/tests/BenchmarkTest
Run on (8 X 3537.87 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
Load Average: 1.51, 0.94, 0.89
***WARNING*** Library was built as DEBUG. Timings may be affected.
-----------------------------------------------------------
Benchmark                 Time             CPU   Iterations
-----------------------------------------------------------
BM_ProcessUpdate      11225 ns        11219 ns        62881
[100%] Built target RunBenchmarkTest
```

