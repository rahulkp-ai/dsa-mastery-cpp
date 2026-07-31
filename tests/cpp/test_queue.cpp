#include "test_common.hpp"
#include "../../cpp/queues/queue.cpp"

int main() {
    CHECK_EQ(dsa::slidingWindowMax({1, 3, -1, -3, 5, 3, 6, 7}, 3), std::vector<int>{3, 3, 5, 5, 6, 7});
    return 0;
}
