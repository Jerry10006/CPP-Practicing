#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> nums(N), dp;
    for (auto& n: nums) cin >> n;

    for (auto& n: nums)
    {
        int pos = lower_bound(dp.begin(), dp.end(), n) - dp.begin();
        if (pos == dp.size()) dp.push_back(n);
        else dp[pos] = n;
    }

    cout << dp.size();
    return 0;
}
