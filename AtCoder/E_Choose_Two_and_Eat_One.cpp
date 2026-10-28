#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

#define pii pair<ll, ll>
priority_queue<pair<ll, pii>, vector<pair<ll, pii>>> pq;

ll qpow(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;

    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

struct DSU
{
    vector<ll> parent, sz;
    DSU(ll n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.resize(n + 1, 1);
    }

    ll find(ll a)
    {
        if (a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    bool unite(ll a, ll b)
    {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<ll> balls(N);
    for (auto& b: balls) cin >> b;
    DSU dsu(N);

    for (ll i = 0; i < N; i++)
    {
        for (ll j = i + 1; j < N; j++)
        {
            ll cost = (qpow(balls[i], balls[j], M) + qpow(balls[j], balls[i], M)) % M;
            pq.push({cost, {i, j}});
        }
    }

    ll ans = 0, t = 0;
    while (true)
    {
        auto [cost, node] = pq.top();
        auto [a, b] = node;
        pq.pop();
        if (dsu.unite(a, b))
        {
            t++;
            ans += cost;
            if (t == N - 1) break;
        }
    }
    
    cout << ans;
    return 0;
}
