//ai說的，這題最後公式可以被推成∑(ti - X * wi) >= 0，然後就可以二分搜了
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

struct cow
{
    int weight, talented;
};

bool check(double val, vector<cow>& cows, int N, int W)
{
    vector<double> dp(W + 1, -1e18);
    dp[0] = 0;
    for (int i = 0; i < N; i++) //cow
    {
        double value = cows[i].talented - val * cows[i].weight;
        for (int j = W; j >= 0; j--) //weight
        {
            if (dp[j] == -1e18) continue;

            int next_w = min(W, j + cows[i].weight);
            dp[next_w] = max(dp[next_w], dp[j] + value);
        }
    }

    if (dp[W] >= 0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    int N, W;
    cin >> N >> W;
    vector<cow> cows(N);
    for (auto& [w, t]: cows) cin >> w >> t;


    double l = 0, r = 1000, ans = 0;
    for (int i = 0; i < 50; i++)
    {
        double mid = l + (r - l) / 2;
        if (check(mid, cows, N, W))
        {
            ans = mid;
            l = mid;
        }
        else r = mid;
    }

    cout << static_cast<int>(ans * 1000);
    return 0;
}