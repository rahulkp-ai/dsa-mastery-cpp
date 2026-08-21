#include "test_common.hpp"
#include "../../cpp/stacks/stack.cpp"

int main()
{
    CHECK(dsa::validParentheses("()[]{}"));
    CHECK_EQ((dsa::nextGreaterElement({2, 1, 2, 4, 3})), (std::vector<int>{4, 2, 4, -1, -1}));
    return 0;
}
