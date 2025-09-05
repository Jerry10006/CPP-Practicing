//
// Created by 蔡杰叡 on 2025/9/3.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M, cnt = 0;
    cin >> N >> M;
    vector<string> Spot(N + 5);
    vector<string> NonSpot(N + 5);

    for (int i = 0; i < N; i++)
    {
        string genome;
        cin >> genome;
        Spot[i] = genome;
    }
    for (int i = 0; i < N; i++)
    {
        string genome;
        cin >> genome;
        NonSpot[i] = genome;
    }

    for (int i = 0; i < M; i++)
    {
        unordered_set<char> SpotSet;
        unordered_set<char> NonSpotSet;
        bool repeat = false;
        for (int j = 0; j < N; j++)
        {
            SpotSet.insert(Spot[j][i]);
            NonSpotSet.insert(NonSpot[j][i]);
            if (SpotSet.count(NonSpot[j][i]) || NonSpotSet.count(Spot[j][i]))
            {
                repeat = true;
                break;
            }
        }
        if (!repeat) cnt++;
    }
    cout << cnt << endl;
    return 0;
}