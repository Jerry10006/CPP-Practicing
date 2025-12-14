#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void DFS(int node, vector<set<int>>& graph, set<int>& visited)
{
    visited.insert(node);
    for (const auto& n: graph[node])
    {
        if (visited.count(n) == 0)
        {
            DFS(n, graph, visited);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int N;
    cin >> N;
    vector<set<int>> arrive(N + 1);
    vector<int> outDegree(N + 1, 0);

    for (int i = 0; i < N - 1; i++)
    {
        int ai, bi;
        cin >> ai >> bi;
        arrive[bi].insert(ai);
        outDegree[ai]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (outDegree[i] == 0)
        {
            set<int> node;
            DFS(i, arrive, node);
            if (node.size() == N)
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}