#include "test_common.hpp"
#include "../../cpp/sorting/sorting.cpp"

int main()
{
    std::vector<int> arr{64, 34, 25, 12, 22, 11, 90};
    auto arr1 = arr;
    auto arr2 = arr;
    dsa::mergeSort(arr1, 0, static_cast<int>(arr1.size()) - 1);
    dsa::quickSort(arr2, 0, static_cast<int>(arr2.size()) - 1);
    CHECK_EQ((arr1), (std::vector<int>{11, 12, 22, 25, 34, 64, 90}));
    CHECK_EQ((arr2), (std::vector<int>{11, 12, 22, 25, 34, 64, 90}));
    return 0;
}
