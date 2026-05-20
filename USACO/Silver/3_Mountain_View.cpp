#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int N;
    cin >> N;
    vector<pair<int, int>> Mt(N);

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        Mt[i] = {x - y, x + y};
    }

    sort(Mt.begin(), Mt.end(), [](auto& a, auto& b)
    {
        auto& [l1, r1] = a;
        auto& [l2, r2] = b;
        if (l1 != l2) return l1 < l2;
        else return r1 > r2;
    });

    int maxR = -1e9, ans = 0;
    for (int i = 0; i < N; i++)
    {
        auto& [l, r] = Mt[i];
        if (r > maxR)
        {
            ans++;
            maxR = r;
        }
    }
    cout << ans;
    return 0;
}
