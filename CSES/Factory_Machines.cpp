#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool check(const int t, const ll time, vector<int>& factory)
{
    ll products = 0;
    for (auto machine: factory)
    {
        products += time / machine;
        if (products >= t) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t;
    cin >> n >> t;
    vector<int> factory(n);

    for (auto& machine: factory) cin >> machine;

    ll l = 0, r = 1e18 + 7, ans = 0;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(t, mid, factory))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans;
}