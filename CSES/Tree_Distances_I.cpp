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

vector<int> dist;
vector<vector<int>> adj;
int maxDist = -1;
int node;

void dfs(int n, int d, int p)
{
    if (d > maxDist) node = n, maxDist = d;
    dist[n] = max(dist[n], d);
    for (auto u: adj[n])
    {
        if (u != p) dfs(u, d + 1, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    adj.resize(N + 1);
    dist.resize(N + 1, 0);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int A, B;
    maxDist = -1;
    dfs(1, 0, -1);
    A = node;
    maxDist = -1;
    dfs(A, 0, -1);
    B = node;

    dfs(A, 0, -1);
    dfs(B, 0, -1);

    for (int i = 1; i <= N; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}
