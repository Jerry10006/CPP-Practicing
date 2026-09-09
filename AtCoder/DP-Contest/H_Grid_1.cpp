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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    const int MOD = 1e9 + 7;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<int>> dp(H, vector<int>(W, 0));

    for (auto& r: grid) for (auto& c: r) cin >> c;
    dp[0][0] = 1;

    for (int r = 1; r < H; r++) if (grid[r][0] == '.' && grid[r - 1][0] == '.') dp[r][0] = dp[r - 1][0];
    for (int c = 1; c < W; c++) if (grid[0][c] == '.' && grid[0][c - 1] == '.') dp[0][c] = dp[0][c - 1];

    for (int r = 1; r < H; r++)
    {
        for (int c = 1; c < W; c++)
        {
            if (grid[r][c] == '#') continue;
            if (grid[r - 1][c] == '.') dp[r][c] = (dp[r][c] + dp[r - 1][c]) % MOD;
            if (grid[r][c - 1] == '.') dp[r][c] = (dp[r][c] + dp[r][c - 1]) % MOD;
        }
    }

    cout << dp[H - 1][W - 1];
    return 0;
}
