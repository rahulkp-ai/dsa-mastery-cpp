/**
 * Competitive Programming Template - C++20
 * ==========================================
 * Fast I/O, common includes, useful macros and aliases.
 *
 * Usage: Copy this as starting point for CP problems.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

// ===== ALIASES =====
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// ===== MACROS =====
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

// ===== FAST I/O =====
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ===== CONSTANTS =====
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// ===== MODULAR ARITHMETIC =====
ll mod(ll a, ll m = MOD) { return ((a % m) + m) % m; }
ll power(ll base, ll exp, ll mod = MOD)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}
ll modInverse(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }

// ===== DSU =====
struct DSU
{
    vi parent, rnk;
    int components;
    DSU(int n) : parent(n), rnk(n, 0), components(n)
    {
        iota(all(parent), 0);
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (rnk[x] < rnk[y])
            swap(x, y);
        parent[y] = x;
        if (rnk[x] == rnk[y])
            ++rnk[x];
        --components;
        return true;
    }
};

// ===== SEGMENT TREE =====
struct SegTree
{
    int n;
    vi tree;
    SegTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int s, int e, int idx, int val)
    {
        if (s == e)
        {
            tree[node] = val;
            return;
        }
        int mid = (s + e) / 2;
        if (idx <= mid)
            update(2 * node, s, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, e, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

    int query(int node, int s, int e, int l, int r)
    {
        if (r < s || e < l)
            return 0;
        if (l <= s && e <= r)
            return tree[node];
        int mid = (s + e) / 2;
        return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

// ===== SOLUTION =====
void solve()
{
    // TODO: Write solution here
    int n;
    if (!(cin >> n))
        return;
    cout << n << "\n";
}

#if !defined(UNIT_TESTING)
int main()
{
    fastIO();
    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases
    while (t--)
        solve();
    return 0;
}
#endif // UNIT_TESTING