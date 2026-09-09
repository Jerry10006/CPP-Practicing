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

    int N, K;
    cin >> N >> K;
    vector<int> high(N), cost(N, 1e9);
    for (auto& h: high) cin >> h;
    cost[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i + j >= N) break;
            cost[i + j] = min(cost[i + j], cost[i] + abs(high[i] - high[i + j]));
        }
    }

    cout << cost[N - 1];
    return 0;
}
