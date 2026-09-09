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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, ans = 1e9;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        queue<int> q;
        q.push(i);
        vector<int> parent(N + 1, -1), dist(N + 1, -1);
        dist[i] = 0;

        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            for (auto a: graph[now])
            {
                if (dist[a] == -1)
                {
                    parent[a] = now;
                    dist[a] = dist[now] + 1;
                    q.push(a);
                }
                else if (parent[now] != a)
                {
                    ans = min(ans, dist[a] + dist[now] + 1);
                }
            }
        }
    }

    if (ans == 1e9) cout << -1;
    else cout << ans;
}
