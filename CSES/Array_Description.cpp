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

    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(N, vector<ll>(M + 1, 0));
    vector<ll> nums(N);
    for (auto& n: nums) cin >> n;
    if (nums[0] == 0) for (ll i = 1; i <= M; i++) dp[0][i] = 1;
    else dp[0][nums[0]] = 1;

    const ll MOD = 1e9 + 7;
    for (ll i = 1; i < N; i++)
    {
        if (nums[i] != 0)
        {
            if (nums[i] - 1 >= 1) dp[i][nums[i]] = (dp[i][nums[i]] + dp[i - 1][nums[i] - 1]) % MOD;
            dp[i][nums[i]] = (dp[i][nums[i]] + dp[i - 1][nums[i]]) % MOD;
            if (nums[i] + 1 <= M) dp[i][nums[i]] = (dp[i][nums[i]] + dp[i - 1][nums[i] + 1]) % MOD;
        }
        else
        {
            for (ll j = 1; j <= M; j++)
            {
                if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j + 1 <= M) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= M; i++)
    {
        ans = (ans + dp[N - 1][i]) % MOD;
    }
    cout << ans;
}
