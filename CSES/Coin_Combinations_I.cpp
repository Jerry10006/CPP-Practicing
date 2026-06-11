#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> value(n);
    for (auto& v: value) cin >> v;
    vector<ll> dp(x + 1);
    dp[0] = 1;
    const ll MOD = 1e9 + 7;

    for (ll i = 1; i <= x; i++)
    {
        for (auto& v: value)
        {
            if (i - v >= 0)
            {
                dp[i] = (dp[i] + dp[i - v]) % MOD;
            }
        }
    }

    cout << dp[x];
    return 0;
}
