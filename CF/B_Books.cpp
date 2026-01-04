#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> book(n);

    for (auto& b: book) cin >> b;

    int l = 0, r = -1, time = 0, ans = 0;

    while (r < n - 1)
    {
        if (time + book[r + 1] <= t)
        {
            time += book[r + 1];
            r++;
        }
        else
        {
            if (l <= r)
            {
                time -= book[l];
                l++;
            }
            else
            {
                l++;
                r = l - 1;
            }
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}
