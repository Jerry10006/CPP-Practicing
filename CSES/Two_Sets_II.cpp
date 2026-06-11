//這題有一個很漂亮的解法，找1~N-1就好，就不用管模逆元了
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

    const ll total = (1 + N) * N / 2;

    if (total & 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> nums(N - 1), dp(total / 2 + 1);
    for (int i = 0; i < N - 1; i++) nums[i] = i + 1;
    const int MOD = 1e9 + 7;
    dp[0] = 1;

    for (auto& n: nums)
    {
        for (int i = total / 2; i >= 0; i--)
        {
            if (i - n >= 0) dp[i] = (dp[i] + dp[i - n]) % MOD;
        }
    }

    cout << dp[total / 2];
    return 0;
}
