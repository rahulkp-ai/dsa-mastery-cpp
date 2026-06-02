/**
 * Maximum Subarray (Kadane's Algorithm) - C++20
 * ===============================================
 * Time:  O(n)
 * Space: O(1)
 * LeetCode #53
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
namespace dsa
{
    int maxSubarray(const std::vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i)
        {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
    }
} // namespace name
int main()
{
    using namespace dsa;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Max subarray sum: " << maxSubarray(nums) << "\n"; // 6
    return 0;
}