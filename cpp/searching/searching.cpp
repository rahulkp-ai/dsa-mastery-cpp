/**
 * Searching Algorithms — C++20
 * ==============================
 * Time: O(log n) for binary search
 * Space: O(1) iterative
 */
#include <iostream>
#include <vector>
#include <algorithm>

namespace dsa {

int binarySearch(const std::vector<int>& nums, int target) {
    int lo = 0, hi = static_cast<int>(nums.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int searchRotated(const std::vector<int>& nums, int target) {
    int lo = 0, hi = static_cast<int>(nums.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[lo] <= nums[mid]) { // Left sorted
            if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else { // Right sorted
            if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    std::vector<int> sorted = {1,3,5,7,9,11};
    std::cout << dsa::binarySearch(sorted, 7) << "\n"; // 3
    std::cout << dsa::binarySearch(sorted, 4) << "\n"; // -1

    std::vector<int> rotated = {4,5,6,7,0,1,2};
    std::cout << dsa::searchRotated(rotated, 0) << "\n"; // 4
    return 0;
}
#endif // UNIT_TESTING
