#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool check(vector<int>& nums, ll val, int k)
{
    ll sum = nums[0];
    int splits = 0;
    for (int r = 0; r < nums.size(); sum += nums[++r])
    {
        if (nums[r] > val) return false;
        if (sum + nums[r + 1] > val)
        {
            splits++;
            sum = 0;
        }
    }
    splits++;
    if (splits <= k) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (auto& num: nums) cin >> num;

    ll low = 0, high = 1e18, ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(nums, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << ans;
    return 0;
}
