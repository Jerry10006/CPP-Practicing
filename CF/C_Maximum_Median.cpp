#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool check(const ll midIndex, const vector<ll>& nums, ll target, ll k, ll n)
{
    ll cost = 0;
    for (ll i = midIndex; i < n; i++)
    {
        if (nums[i] < target) cost += (target - nums[i]);
        if (cost > k){return false;}
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, MAX = 2e9 + 7;
    cin >> n >> k;
    vector<ll> nums(n);
    for (auto& num: nums) cin >> num;

    sort(nums.begin(), nums.end());
    ll middle = (n + 1) / 2 - 1; //index
    ll low = nums[middle], high = MAX, mid;

    while (low < high)
    {
        mid = low + (high - low + 1) / 2;
        if (check(middle, nums, mid, k, n)) low = mid;
        else high = mid - 1;
    }

    cout << low;
}
