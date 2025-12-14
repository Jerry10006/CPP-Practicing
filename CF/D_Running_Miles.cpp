//Test Case 4 WA
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int total(const multiset<int>& array)
{
    int t = 0;
    for (auto& v: array) t += v;
    return t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> sight(n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            int val;
            cin >> val;
            sight[j] = val;
        }

        int ans = sight[1] + sight[2] + sight[3] - 2;
        multiset<int> top3 = {sight[1], sight[2], sight[3]};
        int l = 1, r = 3; //距離為r - l

        while (r < n)
        {
            r++;
            if (sight[r] > *top3.begin())
            {
                top3.erase(top3.begin());
                top3.insert(sight[r]);
            }
            while (top3.count(sight[l]) == 0) l++;
            ans = max(ans, total(top3) - (r - l));
        }
        cout << ans << endl;
    }
    return 0;
}