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

    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (auto& p:price) cin >> p;
    for (auto& p:pages) cin >> p;
    vector<int> dp(x + 1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) //books
    {
        for (int j = x; j >= 0; j--) //prices
        {
            if (j - price[i] >= 0) dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    cout << dp[x];
    return 0;
}
