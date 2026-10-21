#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
using namespace std;
using ll = long long;

#define pii pair<int, int>
vector<int> nums;

bool check(int val, int X, int Y)
{
    auto start = lower_bound(nums.begin(), nums.end(), X), end = upper_bound(nums.begin(), nums.end(), val);
    int length = (val - X + 1) - (end - start + 1 - 1);
    return length >= Y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    nums.resize(N);
    for (auto& n: nums) cin >> n;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < Q; i++)
    {
        int X, Y;
        cin >> X >> Y;

        int l = 0, r = 2e9 + 7, ans = 0;
        while (l <= r)
        {
            int mid =  l + (r - l) / 2;
            if (check(mid, X, Y))
            {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}
