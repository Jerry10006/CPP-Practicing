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

vector<vector<int>> adj;
vector<int> visited, ans;
int END = -1;

bool dfs(int node)
{
    visited[node] = 1;

    for (auto to: adj[node])
    {
        if (visited[to] == 2) continue;
        if (END != -1) return false;
        if (visited[to] == 1 && END == -1)
        {
            ans.push_back(to);
            ans.push_back(node);
            END = to;
            return true;
        }
        if (visited[to] == 1) return false;
        if (dfs(to))
        {
            ans.push_back(node);
            if (END == node) return false;
            return true;
        }
    }

    visited[node] = 2;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }


    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 2) continue;
        dfs(i);
    }

    if (END == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for (auto a: ans) cout << a << " ";
    return 0;
}
