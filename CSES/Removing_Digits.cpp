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

#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= N; i++)
    {
        //電神教的簡潔解
        // string s = to_string(i);
        // for (char c : s)
        // {
        //     int num = c - '0';
        //     dp[i] = min(dp[i - num] + 1, dp[i]);
        // }
        for (int j = 1; j <= 9 && i + j <= N; j++)
        {
            bool ok = false;
            int sum = i + j;
            string SUM = to_string(sum);
            for (auto a: SUM)
            {
                a -= '0';
                if (a == j)
                {
                    ok = true;
                    break;
                }
            }
            if (!ok) continue;
            dp[sum] = min(dp[sum], dp[i] + 1);
        }
    }
    cout << dp[N];
    return 0;
}
