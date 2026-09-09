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

    int N;
    cin >> N;
    vector<vector<int>> happiness(N, vector<int>(3)), total_happiness(N, vector<int>(3, 0)); //天數/今天要做什麼
    for (auto& day: happiness)
    {
        for (auto& h: day) cin >> h;
    }

    total_happiness[0][0] = happiness[0][0];
    total_happiness[0][1] = happiness[0][1];
    total_happiness[0][2] = happiness[0][2];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++) //昨天做了什麼
        {
            for (int k = 0; k < 3; k++) //今天要做什麼
            {
                if (k != j)
                {
                    total_happiness[i][k] = max(total_happiness[i][k], total_happiness[i - 1][j] + happiness[i][k]);
                }
            }
        }
    }

    cout << max({total_happiness[N - 1][0], total_happiness[N - 1][1], total_happiness[N - 1][2]});
    return 0;
}
