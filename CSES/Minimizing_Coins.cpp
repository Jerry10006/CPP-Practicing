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

    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 1e9 + 7);
    vector<int> value(n);
    for (auto& v: value) cin >> v;
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (auto& v: value)
        {
            if (i - v >= 0) dp[i] = min(dp[i], dp[i - v] + 1);
        }
    }

    if (dp[x] != 1e9 + 7) cout << dp[x];
    else cout << -1;
    return 0;
}
