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

#define pii pair<ll, ll>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    ll MOD = 1e9 + 7;
    vector<vector<pii>> flights(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        flights[a].push_back({c, b});
    }

    vector<ll> price(N + 1, 1e18), roads(N + 1, 0), MIN(N + 1, 1e18), MAX(N + 1, 0);
    price[1] = 0;
    roads[1] = 1;
    MIN[1] = 0;
    MAX[1] = 0;

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [p, u] = pq.top();
        pq.pop();

        if (p != price[u]) continue;
        for (auto [w, v]: flights[u])
        {
            if (price[u] + w < price[v])
            {
                price[v] = price[u] + w;
                roads[v] = roads[u];
                MIN[v] = MIN[u] + 1;
                MAX[v] = MAX[u] + 1;
                pq.push({price[v], v});
            }
            else if (price[u] + w == price[v])
            {
                roads[v] = (roads[v] + roads[u]) % MOD;
                MIN[v] = min(MIN[v], MIN[u] + 1);
                MAX[v] = max(MAX[v], MAX[u] + 1);
            }
        }
    }

    cout << price[N] << " ";
    cout << roads[N] << " ";
    cout << MIN[N] << " ";
    cout << MAX[N];
}
