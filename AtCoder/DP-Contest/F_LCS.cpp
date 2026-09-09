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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int Slength = s.length(), Tlength = t.length();
    vector<vector<int>> dp(Slength, vector<int>(Tlength, 0));
    dp[0][0] = 0;
    if (s[0] == t[0]) dp[0][0] = 1;

    for (int i = 1; i < Slength; i++)
    {
        if (s[i] == t[0]) dp[i][0] = 1;
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    }
    for (int i = 1; i < Tlength; i++)
    {
        if (t[i] == s[0]) dp[0][i] = 1;
        dp[0][i] = max(dp[0][i], dp[0][i - 1]);
    }

    for (int i = 1; i < Slength; i++)
    {
        for (int j = 1; j < Tlength; j++)
        {
            if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int r = Slength - 1, c = Tlength - 1;
    string ans;
    while (r >= 0 && c >= 0)
    {
        if (r == 0 && c == 0)
        {
            if (s[0] == t[0]) ans = ans + s[0];
            break;
        }

        if (r == 0)
        {
            if (dp[0][c] == dp[0][c - 1]){c--; continue;}
            if (s[0] == t[c]) ans = ans + s[0];
            break;
        }

        if (c == 0)
        {
            if (dp[r][0] == dp[r - 1][0]){r--; continue;}
            if (s[r] == t[0])ans = ans + s[r];
            break;
        }


        if (r - 1 >= 0 && c - 1 >= 0 && s[r] == t[c] && dp[r - 1][c - 1] + 1 == dp[r][c])
        {
            ans = ans + s[r];
            r--, c--;
            continue;
        }
        if (r - 1 >= 0 && dp[r - 1][c] == dp[r][c])
        {
            r--;
            continue;
        }
        if (c - 1 >= 0 && dp[r][c - 1] == dp[r][c])
        {
            c--;
            continue;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
