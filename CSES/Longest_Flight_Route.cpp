#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> InDegree(N + 1);
    vector<int> ans(N + 1, -1), parent(N + 1);

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        InDegree[b]++;
    }

    queue<int> q;
    vector<int> ordered;
    for (int i = 1; i <= N; i++) if (InDegree[i] == 0)
    {
        q.push(i);
        ordered.push_back(i);
        ans[i] = 1;
    } 

    while (!q.empty()){
        int now = q.front();
        q.pop();

        for (auto v: adj[now]){
            InDegree[v]--;
            if (InDegree[v] == 0){
                q.push(v);
                ordered.push_back(v);
            }
        }
    }

    for (auto u: ordered)
    {
        for (auto v: adj[u])
        {
            ans[v] = max(ans[v], ans[u] + 1);
            parent[v] = u;
        }
    }

    if (ans[N] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans[N] << "\n";

    int now = N, next = N;
    vector<int> Ans;

    while (now != 1){
        now = next;
        Ans.push_back(now);
        next = parent[now];
    }
    reverse(Ans.begin(), Ans.end());

    for (auto a: Ans) cout << a << " ";

    return 0;
}