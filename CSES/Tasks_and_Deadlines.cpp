//這題我自己的理解是已實現收益，因為你前面賺得多就會影響到後面還沒實現的收益賺得少，所以要使受影響個數最少
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
    vector<pair<int, int>> task(N);

    for (auto& [duration, deadline]: task)
    {
        cin >> duration >> deadline;
    }

    sort(task.begin(), task.end());

    ll ans = 0, time = 0;;
    for (auto& [duration, deadline]: task)
    {
        time += duration;
        ans += deadline - time;
    }

    cout << ans;
    return 0;
}
