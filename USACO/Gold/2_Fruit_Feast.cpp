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

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int T, A, B;
    cin >> T >> A >> B;
    vector<bool> dp1(T + 1);
    dp1[0] = true;

    for (int i = A; i <= T; i++) if (dp1[i - A]) dp1[i] = true;
    for (int i = B; i <= T; i++) if (dp1[i - B]) dp1[i] = true;

    vector<bool> dp2(T + 1);
    dp2[0] = true;
    for (int i = 0; i <= T; i++) dp2[i / 2] = dp2[i / 2] || dp1[i];

    for (int i = A; i <= T; i++) if (dp2[i - A]) dp2[i] = true;
    for (int i = B; i <= T; i++) if (dp2[i - B]) dp2[i] = true;

    for (int i = T; i >= 0; i--)
    {
        if (dp1[i] || dp2[i])
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
