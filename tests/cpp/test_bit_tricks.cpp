#include "test_common.hpp"
#include "../../cpp/bit_manipulation/bit_tricks.cpp"

int main() {
    CHECK(dsa::singleNumber({4, 1, 2, 1, 2}) == 4);
    CHECK(dsa::countBits(5) == 2);
    CHECK(dsa::isPowerOfTwo(8));
    CHECK(!dsa::isPowerOfTwo(10));
    CHECK(dsa::missingNumber({3, 0, 1}) == 2);
    return 0;
}
