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

        tree[node] = tree[2 * node] + tree[2 * node + 1];
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

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r) return 0;
        if (l >= ql && r <= qr) return tree[node];

        int mid = l + (r - l) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

}
