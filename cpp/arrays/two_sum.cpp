/**
 * Two Sum - C++20
 * ================
 * Time:  O(n)
 * Space: O(n)
 * LeetCode #1
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>

namespace dsa
{

    // O(n) hash map approach
    std::vector<int> twoSum(const std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            int complement = target - nums[i];
            if (auto it = seen.find(complement); it != seen.end())
            {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }

} // namespace dsa

#if !defined(UNIT_TESTING)
int main()
{
    using namespace dsa;
    auto result = twoSum({2, 7, 11, 15}, 9);
    std::cout << "[" << result[0] << ", " << result[1] << "]\n"; // [0, 1]
    return 0;
}
#endif // UNIT_TESTING
// Compile: g++ -std=c++20 -O2 -o two_sum two_sum.cpp
