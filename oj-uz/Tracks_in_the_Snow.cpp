#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <queue>

#define pii pair<int, int>

using namespace std;
using ll = long long;

vector<vector<char>> grid;
vector<vector<int>> layer;
vector<pii> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    grid.resize(H, vector<char>(W));
    layer.resize(H, vector<int>(W, -1));

    for (auto& h: grid) for (auto& w: h) cin >> w;

    deque<pii> q;
    q.push_front({0, 0});
    layer[0][0] = 1;
    int maxLayer = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop_front();

        for (auto [dx, dy]: direction)
        {
            int xx = x + dx, yy = y + dy;
            if (!(xx >= 0 && xx < H && yy >= 0 && yy < W)) continue;
            if (layer[xx][yy] != -1) continue;
            if (grid[xx][yy] == '.') continue;

            if (grid[xx][yy] == grid[x][y])
            {
                layer[xx][yy] = layer[x][y];
                q.push_front({xx, yy});
            }
            else
            {
                layer[xx][yy] = layer[x][y] + 1;
                maxLayer = max(maxLayer, layer[xx][yy]);
                q.push_back({xx, yy});
            }
        }
    }

    cout << maxLayer;
    return 0;
}
