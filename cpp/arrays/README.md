# Arrays — C++20

## STL Array Operations

```cpp
#include <vector>
#include <algorithm>
#include <ranges>  // C++20

std::vector<int> v = {5, 3, 1, 4, 2};

// Sort
std::sort(v.begin(), v.end());

// Binary search
bool found = std::binary_search(v.begin(), v.end(), 3);

// C++20 ranges
std::ranges::sort(v);
auto it = std::ranges::find(v, 3);
```

## Key Algorithms

- `two_sum.cpp` — Hash map O(n)
- `max_subarray.cpp` — Kadane's O(n)
