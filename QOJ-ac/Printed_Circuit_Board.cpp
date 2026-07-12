#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> pos(N);
    vector<int> right(N);
    for (int i = 0; i < N; i++) cin >> pos[i].first >> pos[i].second;
    sort(pos.begin(), pos.end());
    for (int i = 0; i < N; i++) right[i] = pos[i].second;

    vector<int> LIS;
    for (int i = 0; i < N; i++)
    {
        int POS = lower_bound(LIS.begin(), LIS.end(), right[i], greater<>()) - LIS.begin();
        if (POS == LIS.size()) LIS.push_back(right[i]);
        else
        {
            LIS[POS] = right[i];
        }
    }

    cout << LIS.size();
    return 0;
}
