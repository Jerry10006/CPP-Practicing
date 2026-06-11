#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0 }};

void dfs(int x, int y, const vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m)
{
    visited[x][y] = true;
    for (auto& [dx, dy]: direction)
    {
        int xx = x + dx, yy = y + dy;
        if (xx < n && yy < m && xx >= 0 && yy >= 0 && !visited[xx][yy] && grid[xx][yy] == '.') dfs(xx, yy, grid, visited, n, m);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '.'));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                dfs(i, j, grid, visited, n, m);
                ans++;
            }
        }
    }

    cout << ans;
}
