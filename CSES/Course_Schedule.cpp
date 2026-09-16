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

    int N, M;
    cin >> N >> M;
    vector<int> inDeg(N + 1);
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDeg[b]++;
    }

    vector<int> ans;

    queue<int> q;
    for (int i = 1; i <= N; i++) if (inDeg[i] == 0) q.push(i);

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);

        for (auto b: adj[a])
        {
            inDeg[b]--;
            if (inDeg[b] == 0) q.push(b);
        }
    }

    if (ans.size() != N)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (auto a: ans) cout << a << " ";
    return 0;
}
