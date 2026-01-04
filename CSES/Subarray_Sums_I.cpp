#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, ans = 0;
    cin >> n >> x;
    vector<ll> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    };

    for (int i = 1; i <= n; i++) nums[i] += nums[i - 1];
    int r = 1;

    for (int l = 1; l <= n; l++)
    {
        if (nums[r] - nums[l - 1] == x)
        {
            ans++;
        }
        while (nums[r] - nums[l - 1] < x && r < n)
        {
            r++;
            if (nums[r] - nums[l - 1] == x)
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}