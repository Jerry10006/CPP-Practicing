#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> height(N);
    vector<int> dp(N, 1e9);
    for (auto& h: height) cin >> h;
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        if (i + 1 < N) dp[i + 1] = min(dp[i + 1],dp[i] + abs(height[i + 1] - height[i]));
        if (i + 2 < N) dp[i + 2] = min(dp[i + 2], dp[i] + abs(height[i + 2] - height[i]));
    }

    cout << dp[N - 1];
}
