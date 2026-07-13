/**
 * Hashing — C++20
 * ==================
 * Time: O(n) average for hash operations
 * Space: O(n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

namespace dsa {

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (auto& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    std::vector<std::vector<std::string>> result;
    for (auto& [k, v] : groups) result.push_back(v);
    return result;
}

int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int best = 0;
    for (int n : numSet) {
        if (!numSet.count(n - 1)) { // Start of sequence
            int len = 1;
            while (numSet.count(n + len)) ++len;
            best = std::max(best, len);
        }
    }
    return best;
}

} // namespace dsa

#if !defined(UNIT_TESTING)
int main() {
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto groups = dsa::groupAnagrams(strs);
    std::cout << "Anagram groups: " << groups.size() << "\n"; // 3

    std::vector<int> nums = {100,4,200,1,3,2};
    std::cout << "Longest consecutive: " << dsa::longestConsecutive(nums) << "\n"; // 4
    return 0;
}
#endif // UNIT_TESTING
