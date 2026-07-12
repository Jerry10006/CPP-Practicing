#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

ll distance(int Fx, int Fy, int Bx, int By)
{
    return (Bx - Fx) * (Bx - Fx) + (Fy - By) * (Fy - By);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    const ll INF = 1e18;
    int Fx, Fy, Bx, By;
    cin >> Fx >> Fy >> Bx >> By;
    vector<pair<int, int>> FarmerRoute(N + 1, {0, 0}), CowRoute(M + 1, {0, 0});
    for (int i = 1; i <= N; i++)
    {
        char x;
        cin >> x;
        if (x == 'E') FarmerRoute[i].first++;
        if (x == 'W') FarmerRoute[i].first--;
        if (x == 'N') FarmerRoute[i].second++;
        if (x == 'S') FarmerRoute[i].second--;
    }
    for (int i = 1; i <= M; i++)
    {
        char x;
        cin >> x;
        if (x == 'E') CowRoute[i].first++;
        if (x == 'W') CowRoute[i].first--;
        if (x == 'N') CowRoute[i].second++;
        if (x == 'S') CowRoute[i].second--;
    }

    for (int i = 2; i <= N; i++) FarmerRoute[i].first += FarmerRoute[i - 1].first, FarmerRoute[i].second += FarmerRoute[i - 1].second;
    for (int i = 2; i <= M; i++) CowRoute[i].first += CowRoute[i - 1].first, CowRoute[i].second += CowRoute[i - 1].second;

    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i > 0)
            {
                auto& [Fdx, Fdy] = FarmerRoute[i];
                auto& [Bdx, Bdy] = CowRoute[j];
                if (dp[i - 1][j] != INF) dp[i][j] = min(dp[i][j], dp[i - 1][j] + distance(Fx + Fdx, Fy + Fdy, Bx + Bdx, By + Bdy));
            }
            if (j > 0)
            {
                auto& [Fdx, Fdy] = FarmerRoute[i];
                auto& [Bdx, Bdy] = CowRoute[j];
                if (dp[i][j - 1] != INF) dp[i][j] = min(dp[i][j], dp[i][j - 1] + distance(Fx + Fdx, Fy + Fdy, Bx + Bdx, By + Bdy));
            }
            if (i > 0 && j > 0)
            {
                auto& [Fdx, Fdy] = FarmerRoute[i];
                auto& [Bdx, Bdy] = CowRoute[j];
                if (dp[i - 1][j - 1] != INF) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + distance(Fx + Fdx, Fy + Fdy, Bx + Bdx, By + Bdy));
            }
        }
    }

    cout << dp[N][M];
    return 0;
}
