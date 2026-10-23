#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <stack>
using namespace std;
using ll = long long;

#define pii pair<int, int>

vector<bool> visited;
vector<vector<int>> adj;
stack<int> q;
int start = -1;

bool dfs(int n, int p)
{
    visited[n] = true;
    bool ok = false;
    q.push(n);
    for (auto u: adj[n])
    {
        if (u == p) continue;
        if (ok) break;
        if (visited[u])
        {
            start = u;
            q.push(u);
            return true;
        }
        ok = ok || dfs(u, n);
    }
    if (ok) return true;
    q.pop();
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    visited.resize(N + 1, false);
    adj.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                vector<int> ans;
                ans.push_back(q.top());
                q.pop();
                while (!q.empty())
                {
                    ans.push_back(q.top());
                    if (q.top() == start) break;
                    q.pop();
                }

                reverse(ans.begin(), ans.end());
                cout << ans.size() << "\n";
                for (auto a: ans) cout << a << " ";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
