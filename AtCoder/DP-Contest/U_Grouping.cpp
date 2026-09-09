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

    ll N;
    cin >> N;
    vector<vector<ll>> compatibility(N + 1, vector<ll>(N + 1, 0));
    for (ll i = 1; i <= N; i++) for (ll j = 1; j <= N; j++) cin >> compatibility[i][j];
    vector<ll> score(1 << N, 0), dp(1 << N, 0);
    score[0] = 0;
    dp[0] = 0;

    for (ll S = 1; S < (1 << N); S++)
    {
        ll lowbit = S & -S, sum = score[S ^ lowbit];
        for (ll i = 0; i < N; i++)
        {
            if (S & (1 << i) && !(lowbit & (1 << i)))
            {
                sum += compatibility[__builtin_ctz(lowbit) + 1][i + 1];
            }
        }
        score[S] = sum;
    }

    for (ll S = 1; S < (1 << N); S++)
    {
        ll lowbit = S & -S;
        for (ll sub = S; sub > 0; sub = (sub - 1) & S)
        {
            if (!(sub & lowbit)) continue;
            dp[S] = max(dp[S], score[sub] + dp[S & ~sub]);
        }
    }

    cout << dp[(1 << N) - 1];
    return 0;
}
