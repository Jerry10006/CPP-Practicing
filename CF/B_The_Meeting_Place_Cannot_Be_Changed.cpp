#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool Check(vector<pair<ll, ll>>& Pos, double time, ll N)
{
    double l = -1e18, r = 1e18;
    for (ll i = 0; i < N; i++)
    {
        auto [p, s] = Pos[i];
        l = max(l, static_cast<double>(p) - static_cast<double>(s) * time);
        r = min(r, static_cast<double>(p) + static_cast<double>(s) * time);
    }

    return l <= r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<pair<ll, ll>> Pos(N);

    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        Pos[i].first = p;
    }

    for (int i = 0; i < N; i++)
    {
        int s;
        cin >> s;
        Pos[i].second = s;
    }

    sort(Pos.begin(), Pos.end());

    double low = 0, high = 1e9, ans = 0;
    for (int i = 0; i < 100; i++)
    {
        double mid = low + (high - low) / 2;

        if (Check(Pos, mid, N))
        {
            ans = mid;
            high = mid;
        }
        else low = mid;
    }

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
