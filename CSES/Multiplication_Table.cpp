#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

bool check(ll n, ll val, ll mid)
{
    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += min(n, val / i);
    }

    if (count >= mid) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll mid = (1 + n * n) / 2; // total have n^2

    ll low = 1, high = n * n, ans = 0;

    while (low <= high)
    {
        ll middle = low + (high - low) / 2;

        if (check(n, middle, mid))
        {
            ans = middle;
            high = middle - 1;
        }
        else low = middle + 1;
    }

    cout << ans;
    return 0;
}