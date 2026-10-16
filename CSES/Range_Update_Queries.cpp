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

#define pii pair<ll, ll>

struct segTree
{
    vector<ll> tree, lazy;
    ll N;

    segTree(ll n)
    {
        N = n;
        tree.resize(4 * n + 7);
        lazy.resize(4 * n + 7);
    }

    void build(ll node, ll l, ll r, vector<ll>& a)
    {
        if (l == r)
        {
            tree[node] = a[l];
            return;
        }

        ll mid = l + (r - l) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void push(ll node, ll l, ll r)
    {
        if (lazy[node] == 0) return;
        tree[node] += (r - l + 1) * lazy[node];

        if (l != r)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
        return;
    }

    void update(ll node, ll l, ll r, ll ql, ll qr, ll val)
    {
        push(node, l, r);
        if (r < ql || l > qr) return;

        if (l>= ql && r <= qr)
        {
            lazy[node] = val;
            push(node, l, r);
            return;
        }

        ll mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        return;
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        push(node, l, r);
        if (r < ql || l > qr) return 0;

        if (l >= ql && r <= qr) return tree[node];

        ll mid = l + (r - l) / 2;
        return query(2 * node, l, mid, ql, qr) +
            query(2 * node + 1, mid + 1, r, ql, qr);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, Q;
    cin >> N >> Q;

    vector<ll> nums(N + 1);
    for (ll i = 1; i <= N; i++) cin >> nums[i];
    segTree seg(N);
    seg.build(1, 1, N, nums);

    for (ll i = 0; i < Q; i++)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            seg.update(1, 1, N, a, b, u);
        }
        if (n == 2)
        {
            ll k;
            cin >> k;
            cout << seg.query(1, 1, N, k, k) << "\n";
        }
    }
    return 0;
}
