#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int N;
    cin >> N;
    vector<tuple<ll, int, int>> timeLine; //time, add/remove, id;
    set<int> cnt;

    for (int i = 0; i < N; i++)
    {
        ll start, end;
        cin >> start >> end;
        timeLine.push_back({start, 1, i + 1});
        timeLine.push_back({end, -1, i + 1});
    }
    timeLine.push_back({1e9 + 7, 1, N + 1});

    sort(timeLine.begin(), timeLine.end());

    ll allTime = 0;
    vector<ll> AloneTime(N);

    for (int i = 0; i < timeLine.size() - 1; i++)
    {
        auto [time, dif, id] = timeLine[i];
        if (dif == 1) cnt.insert(id);
        if (dif == -1) cnt.erase(id);

        if (get<0>(timeLine[i + 1]) != time)
        {
            if (cnt.size() > 0) allTime += get<0>(timeLine[i + 1]) - 1 - time + 1;
            if (cnt.size() == 1) AloneTime[*cnt.begin() - 1] += get<0>(timeLine[i + 1]) - 1 - time + 1;
        }
    }

    sort(AloneTime.begin(), AloneTime.end());
    cout << allTime - AloneTime[0];
    return 0;
}
