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

struct BIT
{
    ll N;
    vector<ll> tree;

    BIT(ll n, vector<ll>& a)
    {
        N = n;
        tree.resize(n + 1);
        for (ll i = 1; i <= n; i++) update(i, a[i]);
    }

    void update(ll pos, ll val)
    {
        for (ll i = pos; i <= N; i += i & -i) tree[i] += val;
    }

    ll query(ll pos)
    {
        ll val = 0;
        for (ll i = pos; i > 0; i -= i & -i) val += tree[i];
        return val;
    }

    ll query(ll l, ll r)
    {
        return query(r) - query(l - 1);
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
    BIT bit(N, nums);

    for (ll i = 0; i < Q; i++)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        if (n == 1)
        {
            ll dif = b - nums[a];
            nums[a] = b;
            bit.update(a, dif);
        }
        if (n == 2)
        {
            cout << bit.query(a, b) << "\n";
        }
    }
    return 0;
}
