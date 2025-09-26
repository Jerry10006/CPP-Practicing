//
// Created by 蔡杰叡 on 2025/9/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    ll ans = 0;
    ll Min_instability = LLONG_MAX;
    cin >> N;
    vector<ll> weight(2 * N);

    for (int i = 0; i < 2 * N; i++)
    {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());

    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = i + 1; j < 2 * N; j++)
        {
            vector<ll> weightTemp = weight;

            weightTemp.erase(weightTemp.begin() + max(i, j));
            weightTemp.erase(weightTemp.begin() + min(i, j));

            ll instability = 0;

            for (int m = 1; m < 2 * N - 2; m += 2)
            {
                instability += weightTemp[m] - weightTemp[m - 1];
            }
            Min_instability = min(Min_instability, instability);
        }
    }
    cout << Min_instability;
}