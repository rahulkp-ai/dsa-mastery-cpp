/**
 * Greedy Algorithms — C++20
 * ===========================
 * Time: O(n log n) due to sorting
 * Space: O(1) or O(n)
 */
#include <iostream>
#include <vector>
#include <algorithm>

namespace dsa {

bool jumpGame(const std::vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i > maxReach) return false;
        maxReach = std::max(maxReach, i + nums[i]);
    }
    return true;
}

int jumpGameII(const std::vector<int>& nums) {
    int jumps = 0, currentEnd = 0, farthest = 0;
    for (int i = 0; i < (int)nums.size() - 1; ++i) {
        farthest = std::max(farthest, i + nums[i]);
        if (i == currentEnd) { ++jumps; currentEnd = farthest; }
    }
    return jumps;
}

std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> merged = {intervals[0]};
    for (auto& iv : intervals) {
        if (iv[0] <= merged.back()[1])
            merged.back()[1] = std::max(merged.back()[1], iv[1]);
        else
            merged.push_back(iv);
    }
    return merged;
}

} // namespace dsa

int main() {
    std::cout << std::boolalpha;
    std::cout << dsa::jumpGame({2,3,1,1,4}) << "\n";     // true
    std::cout << dsa::jumpGameII({2,3,1,1,4}) << "\n";   // 2

    std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    auto merged = dsa::mergeIntervals(intervals);
    std::cout << "Merged intervals: " << merged.size() << "\n"; // 3
    return 0;
}
