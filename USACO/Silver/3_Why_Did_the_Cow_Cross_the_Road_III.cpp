#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

bool road[101][101][101][101] = {false};

struct DSU
{
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int i)
    {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int a, int b)
    {
        int root_a = find(a), root_b = find(b);
        if (root_a != root_b) parent[root_a] = root_b;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};



int encode(int x, int y){return 1000 * x + y;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("countcross.in", "r", stdin);


    int N, K, R;
    cin >> N >> K >> R;
    vector<pair<int, int>> cows(K);
    for (int i = 0; i < R; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        road[r1][c1][r2][c2] = true;
        road[r2][c2][r1][c1] = true;
    }

    for (auto& [a, b]: cows) cin >> a >> b;

    DSU dsu(N * 2000);
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (auto& [dx, dy]: direction)
            {
                int x = i + dx, y = j + dy;
                if (x > 0 && x <= N && y > 0 && y <= N && !road[i][j][x][y]) dsu.unite(encode(i, j), encode(x, y));
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < K; i++)
    {
        for (int j = i + 1; j < K; j++)
        {
            auto [x1, y1] = cows[i];
            auto [x2, y2] = cows[j];
            if (!dsu.same(encode(x1, y1), encode(x2, y2))) ans++;
        }
    }

    cout << ans;
}