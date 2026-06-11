#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

void dfs(int i, vector<vector<int>>& connection, vector<bool>& visited)
{
    visited[i] = true;
    for (auto& j: connection[i]) if (!visited[j]) dfs(j, connection, visited);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> positiveConnection(N + 1), negativeConnection(N + 1);

    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        positiveConnection[a].push_back(b);
        negativeConnection[b].push_back(a);
    }

    vector<bool> visited(N + 1, false);
    dfs(1, positiveConnection, visited);
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << "\n";
            cout << "1 " << i;
            return 0;
        }
    }
    vector<bool> visitedA(N + 1, false);
    dfs(1, negativeConnection, visitedA);
    for (int i = 1; i <= N; i++)
    {
        if (!visitedA[i])
        {
            cout << "NO" << "\n";
            cout << i << " 1";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
