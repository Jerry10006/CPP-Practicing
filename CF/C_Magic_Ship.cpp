#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

bool check(ll N, pair<ll, ll> start, pair<ll, ll> end, const vector<pair<ll, ll>>& Prefix_Directions, ll val)
{
    auto [x1, y1] = start;
    auto [x2, y2] = end;

    bool CanBeThere = false;

    ll times = val / (static_cast<ll>(Prefix_Directions.size()) - 1);
    ll remainder = val % (static_cast<ll>(Prefix_Directions.size()) - 1);

    x1 += Prefix_Directions[N].first * times + Prefix_Directions[remainder].first;
    y1 += Prefix_Directions[N].second * times + Prefix_Directions[remainder].second;

    if (abs(x2 - x1) + abs(y2 - y1) <= val) CanBeThere = true;

    return CanBeThere;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<ll, ll> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    ll N;
    cin >> N;
    vector<pair<ll, ll>> Directions(N + 1, {0, 0});
    vector<pair<ll, ll>> Prefix_Directions(N + 1, {0, 0});
    for (ll i = 1; i <= N; i++)
    {
        char C;
        cin >> C;
        if (C == 'U') Directions[i].second++;
        if (C == 'D') Directions[i].second--;
        if (C == 'L') Directions[i].first--;
        if (C == 'R') Directions[i].first++;
    }

    for (ll i = 1; i <= N; i++)
    {
        Prefix_Directions[i].first = Directions[i].first + Prefix_Directions[i - 1].first;
        Prefix_Directions[i].second = Directions[i].second + Prefix_Directions[i - 1].second;
    }

    ll low = 0, high = 1e18, ans = -1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (check(N, start, end, Prefix_Directions, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
