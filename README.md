# btc_test

## prerequisites

Needs:
* google test framework (downloaded by cmake at first execution)
* google benchmark framework (needs manual download - below)
* valgrind installation (for valgrind memory tests - need valgrind and ms_print binaries at PATH)

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
┌─(00:19:27)─(michael@prime)─(~/Projects/cpp/binance)
└─► cat `find -name *.xml`
<?xml version="1.0" encoding="UTF-8"?>
<testsuites tests="1" failures="0" disabled="0" errors="0" time="0" timestamp="2025-12-20T00:19:02.309" name="AllTests">
  <testsuite name="OrderBookTest" tests="1" failures="0" disabled="0" skipped="0" errors="0" time="0" timestamp="2025-12-20T00:19:02.309">
    <testcase name="ProcessSnapshotAndUpdates" file="/home/michael/Projects/cpp/binance/tests/main_test.cpp" line="4" status="run" result="completed" time="0" timestamp="2025-12-20T00:19:02.309" classname="OrderBookTest" />
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

## Memory tests

### Page consumption test

Test checks pages ocnsumption (poor accuracy, left as an example and for future use with a big amount of data).
Limitation is set to 100 pages - needs update for correctness.
One-liner for running only page test:
```
(rm -rf build; cmake -B build .; cd build; make all; make RunPageMemoryTest)
```

### Valgrind test

Uses valgrind's massif option for heap and stack consumtion analysis.
One-liner for running test:
```
(rm -rf build; cmake -B build .; cd build; make all; make RunValgrindMemoryTest)
```
Visualazation of the results:
```
(cd build; make PrintValgrindMemoryTestResult)
```
Example output:
```
 ─(21:00:24)─(michael@prime)─(~/Projects/cpp/binance/build)
└─► make PrintValgrindMemoryTestResult
Build type: Release
-- Failed to find LLVM FileCheck
-- git version: v1.8.3-49-g4682db08 normalized to 1.8.3.49
-- Google Benchmark version: 1.8.3.49
-- Performing Test HAVE_STD_REGEX -- success
-- Performing Test HAVE_GNU_POSIX_REGEX -- failed to compile
-- Performing Test HAVE_POSIX_REGEX -- success
-- Performing Test HAVE_STEADY_CLOCK -- success
-- Performing Test HAVE_PTHREAD_AFFINITY -- success
-- Configuring done
-- Generating done
-- Build files have been written to: /home/michael/Projects/cpp/binance/build
Consolidate compiler generated dependencies of target gtest
[ 20%] Built target gtest
Consolidate compiler generated dependencies of target gtest_main
[ 40%] Built target gtest_main
Consolidate compiler generated dependencies of target OrderBook
[ 80%] Built target OrderBook
Consolidate compiler generated dependencies of target MemoryTest
[100%] Built target MemoryTest
==34435== Massif, a heap profiler
==34435== Copyright (C) 2003-2024, and GNU GPL'd, by Nicholas Nethercote et al.
==34435== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
==34435== Command: MemoryTest
==34435== 
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from OrderBookTest
[ RUN      ] OrderBookTest.ProcessSnapshotAndUpdates
initial memory: 70800
after snapshot: 70800
after updates:  70800
[       OK ] OrderBookTest.ProcessSnapshotAndUpdates (38 ms)
[----------] 1 test from OrderBookTest (40 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (62 ms total)
[  PASSED  ] 1 test.
==34435== 
[100%] Built target RunValgrindMemoryTest
--------------------------------------------------------------------------------
Command:            MemoryTest
Massif arguments:   --stacks=yes
ms_print arguments: massif.out.34435
--------------------------------------------------------------------------------


    KB
91.25^                                                                     #  
     |                                                                     #@ 
     |                                                                     #@ 
     |                                                              @@     #@:
     |                                                              @ :::::#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
     |                                                              @ : : :#@@
   0 +----------------------------------------------------------------------->Mi
     0                                                                   2.440

Number of snapshots: 95
 Detailed snapshots: [43, 44, 48 (peak), 52, 62, 72, 82, 92]

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1          1,398              368                0             0          368
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 43      2,177,803              656                0             0          656
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 44      2,229,475           79,880           74,901           187        4,792
93.77% (74,901B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->92.30% (73,728B) 0x499038E: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
| ->92.30% (73,728B) 0x407271E: call_init.part.0 (dl-init.c:74)
|   ->92.30% (73,728B) 0x4072823: call_init (dl-init.c:120)
|     ->92.30% (73,728B) 0x4072823: _dl_init (dl-init.c:121)
|       ->92.30% (73,728B) 0x408C59F: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->01.47% (1,173B) in 14 places, all below massif's threshold (1.00%)

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  3        128,520            1,424                0             0        1,424
  4        197,189            1,608                0             0        1,608
  5        227,899            1,608                0             0        1,608
  6        273,514            1,384                0             0        1,384
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  7        308,914            1,608                0             0        1,608
  8        352,449            1,952                0             0        1,952
  9        407,397            1,960                0             0        1,960
 10        474,001            1,608                0             0        1,608
 11        510,639            1,384                0             0        1,384
 12        561,927            1,944                0             0        1,944
 13        613,791            1,448                0             0        1,448
 14        651,272            1,704                0             0        1,704
 15        694,318            1,608                0             0        1,608
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 16        758,087            1,608                0             0        1,608
 17        807,528            1,864                0             0        1,864
 18        860,268            1,608                0             0        1,608
 19        901,272            1,864                0             0        1,864
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 20        966,897            1,864                0             0        1,864
 21      1,010,097            1,608                0             0        1,608
 22      1,074,725            1,864                0             0        1,864
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 23      1,117,990            1,864                0             0        1,864
 24      1,144,662            1,608                0             0        1,608
 25      1,188,141            1,864                0             0        1,864
 26      1,220,903            1,608                0             0        1,608
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 27      1,267,384            1,608                0             0        1,608
 28      1,320,604            1,864                0             0        1,864
 29      1,379,161            1,864                0             0        1,864
 30      1,420,498            1,384                0             0        1,384
 31      1,469,254            1,608                0             0        1,608
 32      1,504,818            1,664                0             0        1,664
 33      1,568,491            1,608                0             0        1,608
 34      1,614,676            1,864                0             0        1,864
 35      1,649,011            1,608                0             0        1,608
 36      1,699,976            1,384                0             0        1,384
 37      1,758,004            1,608                0             0        1,608
 38      1,825,339            1,608                0             0        1,608
 39      1,875,869            1,608                0             0        1,608
 40      1,904,469            1,608                0             0        1,608
 41      1,961,364            1,384                0             0        1,384
 42      2,007,988            1,608                0             0        1,608
 43      2,048,333            1,864                0             0        1,864
 44      2,099,775            1,608                0             0        1,608
 45      2,152,182            1,864                0             0        1,864
 46      2,218,825            1,864                0             0        1,864
 47      2,267,251            1,864                0             0        1,864
 48      2,322,677            1,384                0             0        1,384
 49      2,357,180            1,864                0             0        1,864
 50      2,371,602            1,608                0             0        1,608
 51      2,386,349            1,608                0             0        1,608
 52      2,400,805            1,952                0             0        1,952
 53      2,415,248            1,608                0             0        1,608
 54      2,429,836            1,864                0             0        1,864
 55      2,444,298            1,864                0             0        1,864
 56      2,458,856            1,864                0             0        1,864
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 57      2,473,273            1,864                0             0        1,864
 58      2,487,822            1,864                0             0        1,864
 59      2,502,246            1,384                0             0        1,384
 60      2,516,717            1,384                0             0        1,384
 61      2,523,179           72,936           72,704             8          224
99.68% (72,704B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->99.68% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
  ->99.68% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
    ->99.68% (72,704B) 0x4006567: call_init (dl-init.c:33)
      ->99.68% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
        ->99.68% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 62      2,525,148           74,656           72,704             8        1,944
97.39% (72,704B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->97.39% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
  ->97.39% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
    ->97.39% (72,704B) 0x4006567: call_init (dl-init.c:33)
      ->97.39% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
        ->97.39% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 63      2,540,037           74,560           72,704             8        1,848
 64      2,554,459           73,400           72,704             8          688
 65      2,568,907           73,536           72,704             8          824
 66      2,583,707           74,560           72,704             8        1,848
 67      2,598,225           73,472           72,704             8          760
 68      2,612,801           74,368           72,704             8        1,656
 69      2,627,747           74,368           72,704             8        1,656
 70      2,637,604           78,824           73,877           187        4,760
93.72% (73,877B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->92.24% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->92.24% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->92.24% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->92.24% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->92.24% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->01.49% (1,173B) in 14 places, all below massif's threshold (1.00%)
  
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 71      2,652,140           77,272           74,997           299        1,976
 72      2,666,583           74,800           74,092           260          448
 73      2,681,001           75,360           74,515           285          560
 74      2,695,422           75,480           74,602           302          576
 75      2,709,840           75,320           74,529           287          504
 76      2,724,266           75,352           74,484           276          592
 77      2,738,692           75,768           75,070           314          384
 78      2,753,112           75,320           74,515           285          520
 79      2,767,590           75,912           75,061           331          520
 80      2,782,383           74,800           74,127           281          392
99.10% (74,127B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->97.20% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->97.20% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->97.20% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->97.20% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->97.20% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->01.90% (1,423B) in 24 places, all below massif's threshold (1.00%)
  
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 81      2,796,817           75,928           75,082           318          528
 82      2,811,240           76,008           74,997           299          712
 83      2,825,664           75,408           74,529           287          592
 84      2,840,087           75,304           74,484           276          544
 85      2,854,726           75,384           74,157           291          936
 86      2,869,358           78,376           75,573           315        2,488
 87      2,883,782           78,000           75,181           299        2,520
 88      2,888,542           79,624           75,613           387        3,624
94.96% (75,613B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->91.31% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->91.31% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->91.31% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->91.31% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->91.31% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->02.37% (1,885B) in 36 places, all below massif's threshold (1.00%)
| 
->01.29% (1,024B) 0x52B9BA3: _IO_file_doallocate (filedoalloc.c:101)
  ->01.29% (1,024B) 0x52C8CDF: _IO_doallocbuf (genops.c:347)
    ->01.29% (1,024B) 0x52C7F5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
      ->01.29% (1,024B) 0x52C66D4: _IO_new_file_xsputn (fileops.c:1243)
        ->01.29% (1,024B) 0x52C66D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
          ->01.29% (1,024B) 0x52B014C: outstring_func (vfprintf-internal.c:239)
            ->01.29% (1,024B) 0x52B014C: __vfprintf_internal (vfprintf-internal.c:1263)
              ->01.29% (1,024B) 0x536FC4A: __printf_chk (printf_chk.c:33)
                ->01.29% (1,024B) 0x12BED0: testing::internal::ColoredPrintf(testing::internal::(anonymous namespace)::GTestColor, char const*, ...) [clone .constprop.1] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                  ->01.29% (1,024B) 0x12FF46: testing::internal::PrettyUnitTestResultPrinter::OnTestIterationStart(testing::UnitTest const&, int) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                    ->01.29% (1,024B) 0x156941: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                      ->01.29% (1,024B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                        ->01.29% (1,024B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 89      2,889,677           81,320           75,701           411        5,208
93.09% (75,701B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->89.40% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->89.40% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->89.40% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->89.40% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->89.40% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->02.43% (1,973B) in 38 places, all below massif's threshold (1.00%)
| 
->01.26% (1,024B) 0x52B9BA3: _IO_file_doallocate (filedoalloc.c:101)
  ->01.26% (1,024B) 0x52C8CDF: _IO_doallocbuf (genops.c:347)
    ->01.26% (1,024B) 0x52C7F5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
      ->01.26% (1,024B) 0x52C66D4: _IO_new_file_xsputn (fileops.c:1243)
        ->01.26% (1,024B) 0x52C66D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
          ->01.26% (1,024B) 0x52B014C: outstring_func (vfprintf-internal.c:239)
            ->01.26% (1,024B) 0x52B014C: __vfprintf_internal (vfprintf-internal.c:1263)
              ->01.26% (1,024B) 0x536FC4A: __printf_chk (printf_chk.c:33)
                ->01.26% (1,024B) 0x12BED0: testing::internal::ColoredPrintf(testing::internal::(anonymous namespace)::GTestColor, char const*, ...) [clone .constprop.1] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                  ->01.26% (1,024B) 0x12FF46: testing::internal::PrettyUnitTestResultPrinter::OnTestIterationStart(testing::UnitTest const&, int) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                    ->01.26% (1,024B) 0x156941: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                      ->01.26% (1,024B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                        ->01.26% (1,024B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 90      2,896,277           82,144           77,541           891        3,712
94.40% (77,541B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->88.51% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->88.51% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->88.51% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->88.51% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->88.51% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->04.64% (3,813B) in 56 places, all below massif's threshold (1.00%)
| 
->01.25% (1,024B) 0x52B9BA3: _IO_file_doallocate (filedoalloc.c:101)
  ->01.25% (1,024B) 0x52C8CDF: _IO_doallocbuf (genops.c:347)
    ->01.25% (1,024B) 0x52C7F5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
      ->01.25% (1,024B) 0x52C66D4: _IO_new_file_xsputn (fileops.c:1243)
        ->01.25% (1,024B) 0x52C66D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
          ->01.25% (1,024B) 0x52B014C: outstring_func (vfprintf-internal.c:239)
            ->01.25% (1,024B) 0x52B014C: __vfprintf_internal (vfprintf-internal.c:1263)
              ->01.25% (1,024B) 0x536FC4A: __printf_chk (printf_chk.c:33)
                ->01.25% (1,024B) 0x12BED0: testing::internal::ColoredPrintf(testing::internal::(anonymous namespace)::GTestColor, char const*, ...) [clone .constprop.1] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                  ->01.25% (1,024B) 0x12FF46: testing::internal::PrettyUnitTestResultPrinter::OnTestIterationStart(testing::UnitTest const&, int) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                    ->01.25% (1,024B) 0x156941: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                      ->01.25% (1,024B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                        ->01.25% (1,024B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 91      2,898,385           83,040           78,389         1,003        3,648
94.40% (78,389B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->87.55% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->87.55% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->87.55% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->87.55% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->87.55% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->05.61% (4,661B) in 59 places, all below massif's threshold (1.00%)
| 
->01.23% (1,024B) 0x52B9BA3: _IO_file_doallocate (filedoalloc.c:101)
  ->01.23% (1,024B) 0x52C8CDF: _IO_doallocbuf (genops.c:347)
    ->01.23% (1,024B) 0x52C7F5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
      ->01.23% (1,024B) 0x52C66D4: _IO_new_file_xsputn (fileops.c:1243)
        ->01.23% (1,024B) 0x52C66D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
          ->01.23% (1,024B) 0x52B014C: outstring_func (vfprintf-internal.c:239)
            ->01.23% (1,024B) 0x52B014C: __vfprintf_internal (vfprintf-internal.c:1263)
              ->01.23% (1,024B) 0x536FC4A: __printf_chk (printf_chk.c:33)
                ->01.23% (1,024B) 0x12BED0: testing::internal::ColoredPrintf(testing::internal::(anonymous namespace)::GTestColor, char const*, ...) [clone .constprop.1] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                  ->01.23% (1,024B) 0x12FF46: testing::internal::PrettyUnitTestResultPrinter::OnTestIterationStart(testing::UnitTest const&, int) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                    ->01.23% (1,024B) 0x156941: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                      ->01.23% (1,024B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                        ->01.23% (1,024B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 92      2,911,195           90,200           84,981           467        4,752
94.21% (84,981B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->80.60% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->80.60% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->80.60% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->80.60% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->80.60% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->09.08% (8,192B) 0x5124023: std::basic_filebuf<char, std::char_traits<char> >::_M_allocate_internal_buffer() (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->09.08% (8,192B) 0x5128015: std::basic_filebuf<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
|   ->09.08% (8,192B) 0x11C24F: getMemoryConsumptionKB() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|     ->09.08% (8,192B) 0x11DC6D: OrderBookTest_ProcessSnapshotAndUpdates_Test::TestBody() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|       ->09.08% (8,192B) 0x162C80: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|         ->09.08% (8,192B) 0x14E527: testing::Test::Run() [clone .part.0] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|           ->09.08% (8,192B) 0x14EA61: testing::TestInfo::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|             ->09.08% (8,192B) 0x14F271: testing::TestSuite::Run() [clone .part.0] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|               ->09.08% (8,192B) 0x1574B8: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|                 ->09.08% (8,192B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|                   ->09.08% (8,192B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|                     
->03.39% (3,061B) in 60 places, all below massif's threshold (1.00%)
| 
->01.14% (1,024B) 0x52B9BA3: _IO_file_doallocate (filedoalloc.c:101)
  ->01.14% (1,024B) 0x52C8CDF: _IO_doallocbuf (genops.c:347)
    ->01.14% (1,024B) 0x52C7F5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
      ->01.14% (1,024B) 0x52C66D4: _IO_new_file_xsputn (fileops.c:1243)
        ->01.14% (1,024B) 0x52C66D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
          ->01.14% (1,024B) 0x52B014C: outstring_func (vfprintf-internal.c:239)
            ->01.14% (1,024B) 0x52B014C: __vfprintf_internal (vfprintf-internal.c:1263)
              ->01.14% (1,024B) 0x536FC4A: __printf_chk (printf_chk.c:33)
                ->01.14% (1,024B) 0x12BED0: testing::internal::ColoredPrintf(testing::internal::(anonymous namespace)::GTestColor, char const*, ...) [clone .constprop.1] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                  ->01.14% (1,024B) 0x12FF46: testing::internal::PrettyUnitTestResultPrinter::OnTestIterationStart(testing::UnitTest const&, int) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                    ->01.14% (1,024B) 0x156941: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                      ->01.14% (1,024B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                        ->01.14% (1,024B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 93      2,911,924           91,744           84,981           467        6,296
92.63% (84,981B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->79.25% (72,704B) 0x50B9939: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->79.25% (72,704B) 0x400647D: call_init.part.0 (dl-init.c:70)
|   ->79.25% (72,704B) 0x4006567: call_init (dl-init.c:33)
|     ->79.25% (72,704B) 0x4006567: _dl_init (dl-init.c:117)
|       ->79.25% (72,704B) 0x40202C9: ??? (in /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2)
|         
->08.93% (8,192B) 0x5124023: std::basic_filebuf<char, std::char_traits<char> >::_M_allocate_internal_buffer() (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
| ->08.93% (8,192B) 0x5128015: std::basic_filebuf<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
|   ->08.93% (8,192B) 0x11C24F: getMemoryConsumptionKB() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|     ->08.93% (8,192B) 0x11DC6D: OrderBookTest_ProcessSnapshotAndUpdates_Test::TestBody() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|       ->08.93% (8,192B) 0x162C80: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|         ->08.93% (8,192B) 0x14E527: testing::Test::Run() [clone .part.0] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|           ->08.93% (8,192B) 0x14EA61: testing::TestInfo::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|             ->08.93% (8,192B) 0x14F271: testing::TestSuite::Run() [clone .part.0] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|               ->08.93% (8,192B) 0x1574B8: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|                 ->08.93% (8,192B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|                   ->08.93% (8,192B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
|                     
->03.34% (3,061B) in 60 places, all below massif's threshold (1.00%)
| 
->01.12% (1,024B) 0x52B9BA3: _IO_file_doallocate (filedoalloc.c:101)
  ->01.12% (1,024B) 0x52C8CDF: _IO_doallocbuf (genops.c:347)
    ->01.12% (1,024B) 0x52C7F5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
      ->01.12% (1,024B) 0x52C66D4: _IO_new_file_xsputn (fileops.c:1243)
        ->01.12% (1,024B) 0x52C66D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
          ->01.12% (1,024B) 0x52B014C: outstring_func (vfprintf-internal.c:239)
            ->01.12% (1,024B) 0x52B014C: __vfprintf_internal (vfprintf-internal.c:1263)
              ->01.12% (1,024B) 0x536FC4A: __printf_chk (printf_chk.c:33)
                ->01.12% (1,024B) 0x12BED0: testing::internal::ColoredPrintf(testing::internal::(anonymous namespace)::GTestColor, char const*, ...) [clone .constprop.1] (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                  ->01.12% (1,024B) 0x12FF46: testing::internal::PrettyUnitTestResultPrinter::OnTestIterationStart(testing::UnitTest const&, int) (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                    ->01.12% (1,024B) 0x156941: testing::internal::UnitTestImpl::RunAllTests() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                      ->01.12% (1,024B) 0x14EBB4: testing::UnitTest::Run() (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                        ->01.12% (1,024B) 0x11B272: main (in /home/michael/Projects/cpp/binance/build/tests/MemoryTest)
                          
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 94      2,926,349           80,928           76,621           539        3,768
 95      2,940,772           81,880           76,653           571        4,656
 96      2,955,198           76,968           75,581           331        1,056
 97      2,969,627           77,112           75,581           331        1,200
 98      2,984,412           75,720           73,728            16        1,976
[100%] Built target PrintValgrindMemoryTestResult
```
```
