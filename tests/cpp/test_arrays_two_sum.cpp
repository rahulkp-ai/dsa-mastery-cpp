#include "test_common.hpp"
#include "../../cpp/arrays/two_sum.cpp"

int main() {
    CHECK_EQ(dsa::twoSum({2, 7, 11, 15}, 9), std::vector<int>{0, 1});
    CHECK_EQ(dsa::twoSum({3, 2, 4}, 6), std::vector<int>{1, 2});
    return 0;
}
