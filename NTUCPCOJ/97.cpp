#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> delicious(n, 0);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        delicious[i] = num;
    }
    sort(delicious.begin(), delicious.end(), greater<int>());
    for (int i = 0; i < k; i ++)
    {
        ans += delicious[i];
    }
    cout << ans;
}
