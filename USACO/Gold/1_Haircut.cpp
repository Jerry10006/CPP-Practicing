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
    vector<ll> tree;
    ll N;

    BIT(ll n)
    {
        tree.resize(n + 1);
        N = n;
    }

    void update(ll pos, ll val)
    {
        for (ll i = pos; i <= N; i += i & -i)
        {
            tree[i] += val;
        }
    }

    ll query(ll pos)
    {
        ll ans = 0;
        for (ll i = pos; i > 0; i -= i & -i) ans += tree[i];
        return ans;
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

    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);

    ll N;
    cin >> N;
    vector<ll> hairs(N + 1), ans(N + 2, 0);
    BIT bit(N + 1);
    for (ll i = 1; i <= N; i++) cin >> hairs[i];

    for (ll i = 1; i <= N; i++)
    {
        ll num = hairs[i] + 1;
        bit.update(num, 1);
        ans[num + 1] += i - bit.query(1, num);
    }

    for (ll i = 2; i <= N; i++) ans[i] += ans[i - 1];
    for (ll i = 1; i <= N; i++) cout << ans[i] << "\n";
    return 0;
}
