/**
 * Bit Manipulation — C++20 (with backwards compatibility fallback)
 * =================================================================
 * Time: O(1) or O(log n)
 * Space: O(1)
 */
#include <iostream>
#include <vector>

// Include <bit> only if the compiler supports C++20
#if __cplusplus >= 202002L
#include <bit>
#endif

namespace dsa
{

    int singleNumber(const std::vector<int> &nums)
    {
        int result = 0;
        for (int n : nums)
            result ^= n;
        return result;
    }

    int countBits(int n)
    {
// If compiling with C++20, use the standard library feature
#if __cplusplus >= 202002L
        return std::popcount(static_cast<unsigned>(n));
// Fallback for older standards using GCC/Clang built-in
#else
        return __builtin_popcount(static_cast<unsigned>(n));
#endif
    }

    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }

    int missingNumber(const std::vector<int> &nums)
    {
        int n = nums.size(), result = n;
        for (int i = 0; i < n; ++i)
            result ^= i ^ nums[i];
        return result;
    }

    // Generate all subsets using bitmask
    std::vector<std::vector<int>> subsets(const std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<std::vector<int>> result;
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            std::vector<int> subset;
            for (int i = 0; i < n; ++i)
                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            result.push_back(subset);
        }
        return result;
    }

} // namespace dsa

int main()
{
    std::cout << "Single Number: " << dsa::singleNumber({2, 2, 1}) << "\n";                 // 1
    std::cout << "Count Bits (7): " << dsa::countBits(7) << "\n";                           // 3
    std::cout << "Is 16 Power of Two: " << std::boolalpha << dsa::isPowerOfTwo(16) << "\n"; // true
    std::cout << "Missing Number: " << dsa::missingNumber({3, 0, 1}) << "\n";               // 2

    auto subs = dsa::subsets({1, 2, 3});
    std::cout << "Subsets count: " << subs.size() << "\n"; // 8
    return 0;
}