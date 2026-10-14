# Quicksort timing

Times three quicksort pivot choices on `int` arrays of 100000, 200000, 300000, 400000, and 500000 elements:

- last element (`quickSort`)
- middle element (`quickSortMod`)
- random index (`quickSortRand`)

Each size is run twice: once filled with `1..n`, and once filled with random values. Each case is sorted 10 times. The program prints the average of those 10 runs in milliseconds. `SplitTimer` in `splittimer.h` measures elapsed time with `std::chrono::steady_clock`.

`partition` always uses the last element as the pivot. The middle and random variants swap the chosen element into that slot before calling it.

## Build and run

`main.cpp` is the only translation unit. It includes `splittimer.h`. A C++17 compiler is enough.

```
g++ -std=c++17 main.cpp -o main
./main
```

The last-element pivot on already sorted input is quadratic, so those runs can take a long time.
