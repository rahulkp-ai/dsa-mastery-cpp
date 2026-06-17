/**
 * Segment Tree — C++20
 * ======================
 * Time: Build O(n), Query O(log n), Update O(log n)
 * Space: O(n)
 *
 * AI/ML: Range statistics for time-series ML, online learning
 */
#include <iostream>
#include <vector>
#include <algorithm>

namespace dsa {

class SegmentTree {
    int n;
    std::vector<int> tree;

    void build(const std::vector<int>& arr, int node, int s, int e) {
        if (s == e) { tree[node] = arr[s]; return; }
        int mid = (s + e) / 2;
        build(arr, 2*node, s, mid);
        build(arr, 2*node+1, mid+1, e);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int node, int s, int e, int idx, int val) {
        if (s == e) { tree[node] = val; return; }
        int mid = (s + e) / 2;
        if (idx <= mid) update(2*node, s, mid, idx, val);
        else update(2*node+1, mid+1, e, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return query(2*node, s, mid, l, r) + query(2*node+1, mid+1, e, l, r);
    }

public:
    SegmentTree(const std::vector<int>& arr) : n(arr.size()), tree(4*arr.size(), 0) {
        build(arr, 1, 0, n-1);
    }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }
};

} // namespace dsa

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    dsa::SegmentTree st(arr);

    std::cout << st.query(1, 3) << "\n"; // 15 (3+5+7)
    st.update(1, 10);
    std::cout << st.query(1, 3) << "\n"; // 22 (10+5+7)
    return 0;
}
