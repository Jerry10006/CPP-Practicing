#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

int dfs(vector<vector<int>>& connection, vector<pair<int, int>>& pos, set<int>& visited, int cow, int& max_x, int& max_y, int& min_x, int& min_y)
{
    visited.insert(cow);
    max_x = max(max_x, pos[cow].first);
    max_y = max(max_y, pos[cow].second);
    min_x = min(min_x, pos[cow].first);
    min_y = min(min_y, pos[cow].second);

    for (auto c: connection[cow])
    {
        if (!visited.count(c)) dfs(connection, pos, visited, c, max_x, max_y, min_x, min_y);
    }

    return (max_x - min_x + max_y - min_y) * 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> connection(N + 1);
    vector<pair<int, int>> pos(N + 1); //x, y
    set<int> visited;
    vector<int> length;

    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    int ans = 1e9;
    for (int i = 1; i <= N; i++)
    {
        if (!visited.count(i))
        {
            int max_x = 0, max_y = 0, min_x = 1e9, min_y = 1e9;
            ans = min(ans, dfs(connection, pos, visited, i, max_x, max_y, min_x, min_y));
        }
    }

    cout << ans;
}
