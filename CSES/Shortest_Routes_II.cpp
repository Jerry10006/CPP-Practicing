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

    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, 1e18));
    for (ll i = 0; i <= N; i++) dist[i][i] = 0;
    for (ll i = 0; i < M; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (ll k = 1; k <= N; k++)
    {
        for (ll i = 1; i <= N; i++)
        {
            for (ll j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (ll i = 0; i < Q; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (dist[a][b] == 1e18)
        {
            cout << -1 << "\n";
            continue;
        }
        cout << dist[a][b] << "\n";
    }
    return 0;
}
