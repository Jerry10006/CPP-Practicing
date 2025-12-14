#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N;
    cin >> N;
    int ans = 0;
    vector<ll> sum;
    vector<int> mod(7, -1);

    for (int i = 0; i < N; i++)
    {
        int cow;
        cin >> cow;
        if (i == 0) sum.push_back(cow);
        else sum.push_back(sum[i - 1] + cow);
    }
    for (int i = 0; i < N; i++) sum[i] %= 7;
    for (int i = 0; i < N; i++)
    {
        if (mod[sum[i]] == -1) mod[sum[i]] = i;
        else ans = max(ans, i - mod[sum[i]]);
    }
    cout << ans;
    return 0;
}