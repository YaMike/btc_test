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
* JUnit XML output for gtest tests for smooth integration with Jenkins (BlueOcean view plugin)
