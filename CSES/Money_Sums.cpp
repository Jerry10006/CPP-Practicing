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

    int N;
    cin >> N;
    vector<int> coins(N);
    for (auto& c:coins) cin >> c;
    vector<int> dp(1e5 + 7, 0);
    dp[0] = 1;

    for (auto& c: coins)
    {
        for (int i = 1e5 + 6; i >= 0; i--)
        {
            if (i - c >= 0 && dp[i - c] == 1) dp[i] = 1;
        }
    }

    int ans = 0;
    for (int i = 1; i < 1e5 + 7; i++) if (dp[i] == 1) ans++;
    cout << ans << "\n";
    for (int i = 1; i < 1e5 + 7; i++) if (dp[i] == 1) cout << i << " ";
    return 0;
}
