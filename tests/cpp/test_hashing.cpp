#include "test_common.hpp"
#include "../../cpp/hashing/hashing.cpp"

int main() {
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto groups = dsa::groupAnagrams(strs);
    CHECK_EQ(groups.size(), 3);
    CHECK_EQ(dsa::longestConsecutive({100, 4, 200, 1, 3, 2}), 4);
    return 0;
}
