#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
using namespace std;
using ll = long long;

#define pii pair<ll, ll>
vector<ll> nums;

bool check(ll x, ll k, ll N)
{
    ll times = 0;
    for (int i = 0; i < N; i++)
    {
        if (nums[i] < x) times += (x - nums[i] + (i + 1) - 1) / (i + 1);
        if (times > k) return false;
    }
    return times <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    nums.resize(N);
    for (auto& n: nums) cin >> n;

    ll l = 0, r = 2e18 + 7, ans = 0;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid, K, N))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans;
    return 0;
}
