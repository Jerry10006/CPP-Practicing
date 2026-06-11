#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int checkPointAmount = 0, archiveAmount = 0;
pair<int, int> Start;

void dfs(int x, int y, int M, int N, int D, vector<vector<int>>& height, vector<vector<int>>& checkPoint, vector<vector<bool>>& visited)
{
    visited[x][y] = true;
    if (checkPoint[x][y] == 1) archiveAmount++;
    for (auto& [dx, dy]: direction)
    {
        int xx = x + dx, yy = y + dy;
        if (xx >= 0 && yy >= 0 && xx < M && yy < N && !visited[xx][yy] && abs(height[x][y] - height[xx][yy]) <= D)
        {
            dfs(xx, yy, M, N, D, height, checkPoint, visited);
        }
    }
}

bool check(int val, int M, int N, vector<vector<int>>& height, vector<vector<int>>& checkPoint)
{
    vector<vector<bool>> visited(M, vector<bool>(N));
    archiveAmount = 0;
    dfs(Start.first, Start.second, M, N, val, height, checkPoint, visited);
    if (archiveAmount == checkPointAmount) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> height(M, vector<int>(N)), checkPoint(M, vector<int>(N));

    for (auto& r: height) for (auto& c: r) cin >> c;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> checkPoint[i][j];
            if (checkPoint[i][j] == 1) checkPointAmount++;
            if (checkPointAmount == 1 && checkPoint[i][j] == 1) Start.first = i, Start.second = j;
        }
    }


    int l = 0, r = 1e9, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l)/2;
        if (check(mid, M, N, height, checkPoint))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans;
    return 0;
}