#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<double> probability(N + 1);
    for (int i = 1; i <= N; i++) cin >> probability[i];

    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] * (1 - probability[i]);
                continue;
            }
            dp[i][j] = dp[i - 1][j - 1] * probability[i] + dp[i - 1][j] * (1 - probability[i]);
        }
    }

    double ans = 0;
    for (int j = 0; j <= N; j++)
    {
        if (j < N - j) continue;
        ans += dp[N][j];
    }

    cout << fixed << setprecision(10) << ans;
    return 0;
}
