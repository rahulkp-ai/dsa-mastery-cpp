#include "test_common.hpp"
#include "../../cpp/fundamentals/fundamentals.cpp"

int main() {
    CHECK_EQ(maxOf(3, 7), 7);
    CHECK_EQ(gcd(48, 18), 6);
    auto root = makeTree();
    CHECK_EQ(root->val, 1);
    return 0;
}
