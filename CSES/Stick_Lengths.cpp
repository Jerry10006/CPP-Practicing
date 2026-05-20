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
    vector<ll> nums(N);
    ll total = 0;

    for (int i = 0; i < N; i++)
    {
        ll tmp;
        cin >> tmp;
        total += tmp;
        nums[i] = tmp;
    }

    sort(nums.begin(), nums.end());
    ll target;
    if (N % 2 == 1) target = nums[(N + 1) / 2 - 1];
    else if (nums[N / 2] % 2 == 1) target = nums[N / 2 + 1 - 1];
    else target = nums[N / 2 - 1];

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += abs(nums[i] - target);
    }

    cout << ans;
}
