# btc_test

## prerequisites
Install benchmarks from google:
```
cd tests
git clone https://github.com/google/benchmark.git

```

## building && running && testing
One-liner to build&run&run_main&run_tests
```
(rm -rf build; cmake -B build . ; cd build; make all; make RunMain; make RunMainTest)
```

