/**
 * Heaps & Priority Queue — C++20
 * ==================================
 * Time: O(log n) push/pop, O(1) top
 * Space: O(n)
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>

namespace dsa {

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> count;
    for (int n : nums) ++count[n];

    // Min-heap of size k: {freq, num}
    using P = std::pair<int,int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> minHeap;

    for (auto& [num, freq] : count) {
        minHeap.push({freq, num});
        if ((int)minHeap.size() > k) minHeap.pop();
    }

    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int kthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int n : nums) {
        minHeap.push(n);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

} // namespace dsa

int main() {
    std::vector<int> nums = {1,1,1,2,2,3};
    auto topK = dsa::topKFrequent(nums, 2);
    std::cout << "Top 2 frequent: ";
    for (int x : topK) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> arr = {3,2,1,5,6,4};
    std::cout << "2nd largest: " << dsa::kthLargest(arr, 2) << "\n"; // 5
    return 0;
}
