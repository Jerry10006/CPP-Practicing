//這題要脫離時間的概念
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
    ll ans = 0;
    cin >> N;
    vector<int> nums(N);
    priority_queue<int, vector<int>> quota;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        quota.push(nums[i]);
        if (i % 2 == 0)
        {
            ans += quota.top();
            quota.pop();
        }
    }

    cout << ans;
    return 0;
}
