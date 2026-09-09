#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int max_node = -1, max_depth = 0;

void dfs(vector<vector<int>>& graph, int depth, int node, int from)
{
    if (depth > max_depth)
    {
        max_depth = depth;
        max_node = node;
    }

    for (auto& g: graph[node])
    {
        if (g != from) dfs(graph, depth + 1, g, node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> graph(N + 1);
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(graph, 0, 1, -1);

    max_depth = 0;

    dfs(graph, 0, max_node, -1);

    cout << max_depth;
    return 0;
}