#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto& A: a) cin >> A;
    cin >> m;
    vector<int> b(m);
    for (auto& B: b) cin >> B;

    vector<int> dp(m, 0), parent(m, -1);

    for (int i = 0; i < n; i++)
    {
        int best_prev_idx = -1, curr_max = 0;

        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                if (curr_max + 1 > dp[j])
                {
                    dp[j] = curr_max + 1;
                    parent[j] = best_prev_idx;
                }
            }
            if (a[i] > b[j])
            {
                if (dp[j] > curr_max)
                {
                    curr_max = dp[j];
                    best_prev_idx = j;
                }
            }
        }
    }

    int max_val = 0, best_end = -1;
    for (int i = 0; i < m; i++)
    {
        if (dp[i] > max_val)
        {
            max_val = dp[i];
            best_end = i;
        }
    }
    cout << max_val << "\n";

    vector<int> ans;
    int curr = best_end;
    while (curr != -1)
    {
        ans.push_back(b[curr]);
        curr = parent[curr];
    }
    reverse(ans.begin(), ans.end());

    for (auto& ANS: ans)
    {
        cout << ANS << " ";
    }
    return 0;
}
