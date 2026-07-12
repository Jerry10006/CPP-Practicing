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
    vector<vector<char>> grid(N, vector<char>(N));

    for (auto& r: grid) for (auto& c: r) cin >> c;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    if (grid[0][0] == '.') dp[0][0] = 1;
    else dp[0][0] = 0;
    vector<pair<int, int>> direction = {{-1, 0}, {0, -1}};

    const int MOD = 1e9 + 7;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '*') continue;
            for (auto& [dx, dy]: direction)
            {
                int x = i + dx, y = j + dy;
                if (x >= 0 && y >= 0 && grid[x][y] != '*') dp[i][j] = (dp[i][j] + dp[x][y]) %MOD;
            }
        }
    }

    cout << dp[N - 1][N - 1];
    return 0;
}
