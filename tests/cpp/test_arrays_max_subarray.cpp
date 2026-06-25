#include "test_common.hpp"
#include "../../cpp/arrays/max_subarray.cpp"

int main() {
    CHECK(dsa::maxSubarray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
    CHECK(dsa::maxSubarray({1}) == 1);
    return 0;
}
