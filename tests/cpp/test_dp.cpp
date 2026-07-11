#include "test_common.hpp"
#include "../../cpp/dynamic_programming/dp.cpp"

int main() {
    CHECK_EQ(dsa::coinChange({1, 2, 5}, 11), 3);
    CHECK_EQ(dsa::longestCommonSubsequence("abcde", "ace"), 3);
    CHECK_EQ(dsa::knapsack({1, 2, 3}, {6, 10, 12}, 5), 22);
    return 0;
}
