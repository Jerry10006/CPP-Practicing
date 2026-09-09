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
    cin >> N >> W;
    vector<pair<ll, ll>> items(N);
    vector<ll> dp(W + 1, 0);
    for (auto& [w, v]: items) cin >> w >> v;

    for (ll i = 0; i < N; i++)
    {
        for (ll j = W; j >= items[i].first; j--)
        {
            dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= W; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}
