#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <set>
using namespace std;
using ll = long long;

struct DSU
{
    vector<int> parent;

    DSU(int N)
    {
        parent.resize(N + 1);
        for (int i = 0; i <= N; i++) parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB) return false;
        parent[rootA] = rootB;
        return true;
    }

    bool same(int a, int b)
    {
        if (find(a) == find(b)) return true;
        return false;
    }
};

set<int> visited;

void dfs(int x, vector<vector<int>>& graph, DSU& dsu, vector<char>& Farm)
{
    visited.insert(x);
    for (auto& y: graph[x])
    {
        if (!visited.count(y))
        {
            if (Farm[x] == Farm[y]) dsu.unite(x, y);
            dfs(y, graph, dsu, Farm);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<char> Farm(N + 1);
    for (int i = 1; i <= N; i++) cin >> Farm[i];
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    DSU dsu(N);

    dfs(1, graph, dsu, Farm);
    string ans;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (Farm[a] == c || !dsu.same(a, b)) ans += '1';
        else ans += '0';
    }

    cout << ans;
    return 0;
}
