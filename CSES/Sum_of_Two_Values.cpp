#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> nums(n);

    for (auto& num: nums) cin >> num.second;
    for (int i = 0; i < n; i++) nums[i].first = i + 1;
    sort(nums.begin(), nums.end(), [](auto a, auto b){return a.second < b.second;});
    int r = n - 1;
    if (n == 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int l = 0; l < n - 1; l++)
    {
        if (nums[l].second + nums[r].second == x)
        {
            cout << nums[l].first << " " << nums[r].first;
            return 0;
        }
        while (nums[l].second + nums[r].second > x)
        {
            if (l + 1 == r || l == r)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
            r--;
            if (nums[l].second + nums[r].second == x)
            {
                cout << nums[l].first << " " << nums[r].first;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}