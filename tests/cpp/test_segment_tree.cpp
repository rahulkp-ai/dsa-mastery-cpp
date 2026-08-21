#include "test_common.hpp"
#include "../../cpp/segment_trees/segment_tree.cpp"

int main() {
    dsa::SegmentTree st({1, 3, 5, 7, 9, 11});
    CHECK_EQ(st.query(1, 3), 15);
    st.update(1, 10);
    CHECK_EQ(st.query(1, 3), 22);
    return 0;
}
