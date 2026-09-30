#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
using namespace std;
using ll = long long;

#define pii pair<int, int>

struct SegTree
{
    int N;
    vector<ll> tree;

    SegTree(int n)
    {
        N = n;
        tree.resize(4 * N + 7);
    }

    void build(int node, int l, int r, vector<ll>& a)
    {
        if (l == r)
        {
            tree[node] = a[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, ll value)
    {
        if (l == r)
        {
            tree[node] = value;
            return;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid) update(2 * node, l, mid, pos, value);
        else update(2 * node + 1, mid + 1, r, pos, value);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l) return 1e9;

        if (l >= ql && r <= qr) return tree[node];

        int mid = l + (r - l) / 2;

        return min(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    SegTree seg_tree(N);
    vector<ll> nums(N + 1);

    for (int i = 1; i <= N; i++) cin >> nums[i];
    seg_tree.build(1, 1, N, nums);

    for (int i = 0; i < Q; i++)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (n == 1) seg_tree.update(1, 1, N, a, b);
        if (n == 2)
        {
            cout << seg_tree.query(1, 1, N, a, b) << "\n";
        }
    }
    return 0;
}
