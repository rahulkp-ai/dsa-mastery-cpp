/**
 * Queue Implementations — C++20
 * ================================
 * Time: O(1) enqueue/dequeue with deque
 * Space: O(n)
 */
#include <iostream>
#include <queue>
#include <deque>
#include <vector>

namespace dsa {

std::vector<int> slidingWindowMax(const std::vector<int>& nums, int k) {
    std::deque<int> dq; // stores indices, front = max
    std::vector<int> result;

    for (int i = 0; i < (int)nums.size(); ++i) {
        // Remove elements outside window
        if (!dq.empty() && dq.front() == i - k) dq.pop_front();
        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

} // namespace dsa

int main() {
    auto result = dsa::slidingWindowMax({1,3,-1,-3,5,3,6,7}, 3);
    for (int x : result) std::cout << x << " "; // 3 3 5 5 6 7
    std::cout << "\n";
    return 0;
}
