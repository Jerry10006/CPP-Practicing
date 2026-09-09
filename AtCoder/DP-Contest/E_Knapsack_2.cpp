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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, W;
    const ll INF = 1e18;
    cin >> N >> W;
    vector<pair<ll, ll>> items(N);
    for (auto& [w, v]: items) cin >> w >> v;
    vector<ll> dp(1e5 + 7, INF); //dp[value] = min weight
    dp[0] = 0;

    for (auto [w, v]: items)
    {
        for (ll i = 1e5 + 5; i >= v; i--)
        {
            if (dp[i - v] == INF) continue;
            dp[i] = min(dp[i], dp[i - v] + w);
        }
    }

    ll ans = 0;
    for (int i = 0; i < 1e5 + 7; i++)
    {
        if (dp[i] <= W && dp[i] != INF) ans = i;
    }

    cout << ans;
    return 0;
}
