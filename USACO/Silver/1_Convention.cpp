#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool check(int M, ll val, const vector<int>& cows, int C)
{
    int i = 0, cars = 0;
    while (i < cows.size())
    {
        int timesDif = 0;
        int start = i;
        for (; i < cows.size() && cows[i] - cows[start] <= val && (i - start) < C; i++){;}
        cars++;
        if (cars > M) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    int N, M, C;
    cin >> N >> M >> C;
    vector<int> cows(N);

    for (auto& cow: cows) cin >> cow;
    sort(cows.begin(), cows.end());

    ll ans = 0, low = 0, high = 1e9 + 7;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(M, mid, cows, C))
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << ans;
}
