#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> pos(N);
    for (auto& [a, b]: pos) cin >> a >> b;

    sort(pos.begin(), pos.end(), [](auto a, auto b)
    {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    vector<int> endPOS(N);
    for (int i = 0; i < N; i++) endPOS[i] = pos[i].second;

    vector<int> LIS;
    for (int i = 0; i < N; i++)
    {
        int POS = lower_bound(LIS.begin(), LIS.end(), endPOS[i]) - LIS.begin();
        if (POS == LIS.size()) LIS.push_back(endPOS[i]);
        else LIS[POS] = endPOS[i];
    }

    cout << LIS.size();
}
