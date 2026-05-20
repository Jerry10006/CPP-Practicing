#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<ll, ll>> events; //end/starts

    for (int i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        events.push_back({b, a});
    }

    sort(events.begin(), events.end());

    ll lastEnd = -1, ans = 0;

    for (int i = 0; i < N; i++)
    {
        auto& [end, start] = events[i];

        if (start >= lastEnd)
        {
            lastEnd = end;
            ans++;
        }
    }

    cout << ans;
}