#include "test_common.hpp"
#include "../../cpp/system_design/system_design.cpp"

int main() {
    dsa::LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    CHECK_EQ(cache.get(1), 1);
    cache.put(3, 3);
    CHECK_EQ(cache.get(2), -1);
    cache.put(4, 4);
    CHECK_EQ(cache.get(1), -1);
    CHECK_EQ(cache.get(3), 3);
    CHECK_EQ(cache.get(4), 4);
    return 0;
}
