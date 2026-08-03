#include "test_common.hpp"
#include "../../cpp/heaps/heap.cpp"

int main()
{
    auto topK = dsa::topKFrequent({1, 1, 1, 2, 2, 3}, 2);
    CHECK_EQ((static_cast<long long>(topK.size())), (2));
    std::vector<int> nums{3, 2, 1, 5, 6, 4};
    CHECK_EQ(dsa::kthLargest(nums, 2), 5);
    return 0;
}
