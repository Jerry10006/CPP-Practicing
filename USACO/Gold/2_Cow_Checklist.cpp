#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

ll distance(pair<int, int> cow1, pair<int, int> cow2)
{
    return (cow2.first - cow1.first) * (cow2.first - cow1.first) + (cow2.second - cow1.second) * (cow2.second - cow1.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int H, G;
    cin >> H >> G;
    const ll INF = 1e18;
    vector<pair<int, int>> Holsteins(H + 1, {0, 0}), Guernseys(G + 1, {0, 0});

    for (int i = 1; i <= H; i++) cin >> Holsteins[i].first >> Holsteins[i].second;
    for (int i = 1; i <= G; i++) cin >> Guernseys[i].first >> Guernseys[i].second;

    vector<vector<vector<ll>>> dp(H + 1, vector<vector<ll>>(G + 1, vector<ll>(2, INF))); //拜訪過幾隻Holsteins/拜訪過幾隻Guernseys/當前是拜訪(0)Holsteins/(1)Guernseys
    dp[1][0][0] = 0;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 0; j <= G; j++)
        {
            if (i > 1)
            {
                if (dp[i - 1][j][0] != INF) dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + distance(Holsteins[i], Holsteins[i - 1]));
                if (dp[i - 1][j][1] != INF && j > 0) dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + distance(Holsteins[i], Guernseys[j]));
            }
            if (j > 1)
            {
                if (dp[i][j - 1][1] != INF) dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + distance(Guernseys[j], Guernseys[j - 1]));
            }
            if (j > 0)
            {
                if (dp[i][j - 1][0] != INF) dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + distance(Holsteins[i], Guernseys[j]));
            }
        }
    }

    cout << dp[H][G][0];
    return 0;
}