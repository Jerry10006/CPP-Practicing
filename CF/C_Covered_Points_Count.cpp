#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<pair<ll, ll>> line;



    for (int i = 0; i < N; i++)
    {
        ll l, r;
        cin >> l >> r;
        line.emplace_back(l, 1);
        line.emplace_back(r + 1, -1);
    }

    line.emplace_back(1e18 + 7, 0);

    sort(line.begin(), line.end());

    vector<ll> ans(N + 1, 0);
    ll covers = 0;
    for (ll i = 0; i < N * 2; i++)
    {
        covers += line[i].second;
        if (line[i].first == line[i + 1].first) continue;

        ans[covers] += (line[i + 1].first - 1) - line[i].first + 1;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
