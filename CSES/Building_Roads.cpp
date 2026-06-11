#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;
using ll = long long;

void dfs(int start, unordered_set<int>& visited, const vector<vector<int>>& graph)
{
    visited.insert(start);
    for (auto& s: graph[start])
    {
        if (!visited.count(s)) dfs(s, visited, graph);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    unordered_set<int> visited;
    vector<int> ans;

    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited.count(i))
        {
            dfs(i, visited, graph);
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }

    return 0;
}
