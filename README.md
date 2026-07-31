# strzcpy

strzcpy is the last word in C string handling. If the source is bigger than the destination, we crash the entire process.

strzcpy cannot be misused, only misunderstood.

(strfcpy and strxcpy are offered as alternatives that don't crash on error.)

## Build and test

```
sudo apt-get install cmake gcc
cmake -B build .
cmake --build build && build/strzcpy_tests
```
