//這題原本我用vector，然後一直找不出為什麼會有兩個test case WA，最後找了很久，問了AI，發現是我忽略了題目給的限制
//"You want to complete course 1 as soon as possible. If there are several ways to do this, you want then to complete course 2 as soon as possible, and so on."
//最後發現只要用set在rev_adj，就可以保證dfs由小到大遍歷
//結果還是WA，我完全想不到原因，只好再去詢問一次AI，發現是因為假設A有B, C兩個dependency，B, C也有自己的dependency
//可能最佳的情況會是先處理B的一部分，然後跑去C，再跑回B，可是dfs會造成他沒有這個彈性，因次我就想到了或許可以使用min heap搭配上Kahn's Algorithm
//但是後來又再次發現這會造成ans是按照字典序排列而非題目要求的，最後發現可以將它理解成數字越大的，優先度越低，因此可以使用max heap並在最後reverse ans即可
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

#define pii pair<int, int>

//此為最初的WA解法
// vector<set<int>> adj, rev_adj;
// vector<int> ans;
// vector<bool> visited;
//
// void dfs(int node)
// {
//     for (auto u: rev_adj[node])
//     {
//         if (visited[u]) continue;
//         dfs(u);
//     }
//     visited[node] = true;
//     ans.push_back(node);
// }
//
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     int N, M;
//     cin >> N >> M;
//
//     adj.resize(N + 1);
//     rev_adj.resize(N + 1);
//     visited.resize(N + 1);
//
//     for (int i = 0; i < M; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         adj[a].insert(b);
//         rev_adj[b].insert(a);
//     }
//
//
//     for (int i = 1; i <= N; i++)
//     {
//         if (visited[i]) continue;;
//         dfs(i);
//     }
//
//     for (auto u: ans) cout << u << " ";
//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> rev_adj(N + 1), adj(N + 1);
    vector<int> rev_InDegree(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
        rev_InDegree[a]++;
    }

    vector<int> ordered;
    priority_queue<int> pq;

    for (int i = 1; i <= N; i++)
    {
        if (rev_InDegree[i] == 0) pq.push(i);
    }

    while (!pq.empty())
    {
        int node = pq.top();
        ordered.push_back(node);
        pq.pop();

        for (auto u: rev_adj[node])
        {
            rev_InDegree[u]--;
            if (rev_InDegree[u] == 0) pq.push(u);
        }
    }

    reverse(ordered.begin(), ordered.end());
    for (auto u: ordered) cout << u << " ";
}