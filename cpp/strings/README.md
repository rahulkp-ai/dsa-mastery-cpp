# Strings — C++20

## Topics
- String manipulation (reverse, palindrome)
- Pattern matching (KMP algorithm)
- Anagram detection
- Sliding window on strings
- Suffix arrays

## Files
- `strings.cpp` — Core string algorithms

## Complexity
| Algorithm | Time | Space |
|-----------|------|-------|
| Palindrome check | O(n) | O(1) |
| KMP search | O(n+m) | O(m) |
| Anagram check | O(n) | O(1) |
| Longest palindrome | O(n²) | O(1) |

## C++ String Tips
```cpp
s.substr(start, len)   // Substring
s.find(pattern)        // First occurrence
s.rfind(pattern)       // Last occurrence
std::reverse(s.begin(), s.end())  // Reverse in place
std::sort(s.begin(), s.end())     // Sort characters
```
