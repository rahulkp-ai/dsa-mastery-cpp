#include "test_common.hpp"
#include "../../cpp/greedy/greedy.cpp"

int main()
{
    CHECK(dsa::jumpGame({2, 3, 1, 1, 4}));
    CHECK_EQ(dsa::jumpGameII({2, 3, 1, 1, 4}), 2);
    std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}};
    auto merged = dsa::mergeIntervals(intervals);
    CHECK_EQ(merged.size(), 2);
    return 0;
}
