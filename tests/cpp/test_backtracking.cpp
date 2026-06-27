#include "test_common.hpp"
#include "../../cpp/backtracking/backtracking.cpp"

int main()
{
    auto subs = dsa::subsets({1, 2, 3});
    CHECK(subs.size() == 8);
    CHECK_EQ(dsa::nQueens(4), 2);
    return 0;
}
