#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool find(vector<pair<int, int>> array, int target, int skip, int n)
{
    int r, end;
    if (skip == n - 1)
    {
        r = n - 2;
        end = n - 3;
    }
    r = n - 1;
    end = n - 2;

    for (int l = 0; l <= end; l++)
    {
        if (l == skip) continue;
        if (r == skip) r--;
        if (array[l].second + array[r].second == target)
        {
            cout << array[skip].first << " " << array[l].first << " " << array[r].first;
            return true;
        }
        if (l == r - 1 || l == r || l > r) return false;
        while (array[l].second + array[r].second > target)
        {
            r--;
            if (r == skip) r--;
            if (array[l].second + array[r].second == target)
            {
                cout << array[skip].first << " " << array[l].first << " " << array[r].first;
                return true;
            }
            if (l == r - 1 || l == r) return false;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums[i].first = i + 1;
        nums[i].second = num;
    }

    sort(nums.begin(), nums.end(), [](auto a, auto b){return a.second < b.second;});
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && nums[i].second == nums[i - 1].second) continue;
        int dif = x - nums[i].second;
        if (find(nums, dif, i, n)) return 0;
    }
    cout << "IMPOSSIBLE";
    return 0;
}