#include "test_common.hpp"
#include "../../cpp/competitive_programming/template.cpp"

int main() {
    CHECK_EQ(mod(10), 10);
    CHECK_EQ(power(2, 10), 1024);
    CHECK_EQ(modInverse(2), 500000004);
    DSU dsu(3);
    CHECK(dsu.unite(0, 1));
    CHECK(dsu.find(0) == dsu.find(1));
    SegTree tree(5);
    tree.update(0, 10);
    tree.update(1, 5);
    CHECK_EQ(tree.query(0, 1), 15);
    return 0;
}
