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

vector<pii> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m)), parent(n, vector<char>(m, '.'));

    pii initial, END;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == 'A') initial = {i, j};
        grid[i][j] = tmp;
    }

    queue<pii> q;
    q.push(initial);
    bool end = false;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy]: direction)
        {
            int xx = x + dx, yy = y + dy;
            if (!(xx >= 0 && xx < n && yy >= 0 && yy < m)) continue;
            if (grid[xx][yy] == '#') continue;
            if (parent[xx][yy] != '.') continue;

            q.push({xx, yy});
            char direct;
            if (dx == 1 && dy == 0) direct = 'D';
            if (dx == -1 && dy == 0) direct = 'U';
            if (dx == 0 && dy == 1) direct = 'R';
            if (dx == 0 && dy == -1) direct = 'L';

            parent[xx][yy] = direct;

            if (grid[xx][yy] == 'B')
            {
                end = true;
                END = {xx, yy};
                break;
            }
        }
        if (end) break;
    }

    if (!end)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    vector<char> ans;
    pii now = END;

    while (true)
    {
        auto [x, y] = now;

        ans.push_back(parent[x][y]);

        pii direct;
        char NowParent = parent[x][y];

        if (NowParent == 'U') direct = direction[0];
        if (NowParent == 'D') direct = direction[1];
        if (NowParent == 'L') direct = direction[2];
        if (NowParent == 'R') direct = direction[3];

        auto [dx, dy] = direct;
        now = {x + dx, y + dy};

        auto [a, b] = now;
        if (grid[a][b] == 'A') break;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto a: ans) cout << a;
}
