#include "test_common.hpp"
#include "../../cpp/searching/searching.cpp"

int main()
{
    CHECK_EQ((dsa::binarySearch({1, 3, 5, 7, 9}, 7)), (3));
    CHECK_EQ((dsa::searchRotated({4, 5, 6, 7, 0, 1, 2}, 0)), (4));
    return 0;
}
