#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> smart(n);
        unordered_map<int, vector<int>> factor;
        for (auto& s: smart) cin >> s;

        sort(smart.begin(), smart.end());

        for (int j = 0; j < n; j++)
        {
            const int nums = smart[j];
            for (int f = 1; f <= (int)sqrt(nums) && f <= m; f++)
            {
                if (nums % f == 0)
                {
                    factor[j].push_back(f);
                    if (f * f != nums) if (nums / f <= m) factor[j].push_back(nums / f);
                }
            }
        }

        int ans = INT_MAX;
        bool skip = false;
        vector<int> cnt(m+1, 0);
        int covered = 0;
        int r = 0;

        for (int f : factor[r]) {
            if (cnt[f] == 0) covered++;
            cnt[f]++;
        }

        for (int l = 0; l < n; l++)
        {
            while (covered < m && r + 1 < n)
            {
                r++;
                for (int f : factor[r]) {
                    if (cnt[f] == 0) covered++;
                    cnt[f]++;
                }
            }

            if (r == n - 1 && covered < m)
            {
                if (ans == INT_MAX) cout << -1 << endl;
                else cout << ans << endl;
                skip = true;
                break;
            }

            int Max = smart[r];
            int Min = smart[l];
            ans = min(ans, Max - Min);

            for (int f : factor[l])
            {
                cnt[f]--;
                if (cnt[f] == 0) covered--;
            }
        }
        if (!skip) cout << ans << endl;
    }
}