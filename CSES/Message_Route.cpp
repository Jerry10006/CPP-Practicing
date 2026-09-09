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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> connection(N + 1);
    bool reached = false;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
        if (a == N || b == N) reached = true;
    }

    if (!reached)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> parent(N + 1, -1);
    parent[1] = -2;
    queue<int> q;
    q.push(1);
    int dist = 0;
    bool keep = true;

    while (!q.empty() && keep)
    {
        dist++;
        int t = q.size();

        for (int i = 0; i < t; i++)
        {
            int a = q.front();
            q.pop();

            if (a == N)
            {
                keep = false;
                break;
            }

            for (auto target: connection[a])
            {
                if (parent[target] != -1) continue;
                q.push(target);
                parent[target] = a;
            }
        }
    }

    if (keep)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << dist << "\n";

    vector<int> route;
    int now = -1, to = N;
    while (now != 1)
    {
        route.push_back(to);
        now = to;
        to = parent[to];
    }
    reverse(route.begin(), route.end());

    for (int i = 0; i < route.size() - 1; i++) cout << route[i] << " ";
    cout << route[route.size() - 1] << endl;
    return 0;
}
