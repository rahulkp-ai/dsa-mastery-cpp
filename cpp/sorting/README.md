# Sorting — C++20

This folder contains a C++ implementation of classic sorting algorithms using modern C++ features.

## Algorithms included

- **Merge Sort**
  - Time complexity: `O(n log n)`
  - Stable sort
  - Divide and conquer approach
- **Quick Sort**
  - Average time complexity: `O(n log n)`
  - Worst-case time complexity: `O(n^2)`
  - In-place partition-based sort

## File

- `sorting.cpp` — demonstrates `mergeSort` and `quickSort` on a sample integer array.

## Compile

```bash
clang++ -std=c++20 sorting.cpp -o sorting
```

## Run

```bash
./sorting
```

## Output

The program prints the sorted results for both algorithms:

```text
Merge Sort: 11 12 22 25 34 64 90
Quick Sort: 11 12 22 25 34 64 90
```

## Notes

- `mergeSort` uses auxiliary storage for merging subarrays.
- `quickSort` uses the last element as the pivot and performs in-place swaps.
- This example is intended for learning and comparing the two fundamental sorting techniques.
