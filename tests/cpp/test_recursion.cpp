#include "test_common.hpp"
#include "../../cpp/recursion/recursion.cpp"

int main()
{
    std::vector<long long> memo(20, -1);
    CHECK_EQ(dsa::fib(10, memo), 55);
    std::vector<int> nums{1, 2};
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    dsa::subsets(nums, 0, path, result);
    CHECK_EQ((static_cast<long long>(result.size())), (4));
    return 0;
}
