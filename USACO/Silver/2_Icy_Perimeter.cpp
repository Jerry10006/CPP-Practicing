#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int area = 0, length = 0;
vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, vector<vector<char>>& grid, set<pair<int, int>>& visited, int N)
{
    visited.insert({x, y});
    if (grid[x][y] == '#') area++;

    for (auto& [dx, dy]: direction)
    {
        if (x + dx < N && y + dy < N && x + dx >= 0 && y + dy >= 0 && grid[x + dx][y + dy] == '#')
        {
            if (!visited.count({x + dx, y + dy})) dfs(x + dx, y + dy, grid, visited, N);
        }
        else length++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    int N;
    cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));

    for (auto& r: grid) for (auto& c: r) cin >> c;
    set<pair<int, int>> visited;

    map<int, set<int>> Count;


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            area = 0, length = 0;
            if (!visited.count({i, j}) && grid[i][j] == '#')
            {
                dfs(i, j, grid, visited, N);
                Count[area].insert(length);
            }
        }
    }

    cout << Count.rbegin()->first << " " << *Count.rbegin()->second.begin();
    return 0;
}
