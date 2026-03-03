#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> start(N), end(N);

    for (int i = 0; i < N; i++)
    {
        int b, e;
        cin >> b >> e;
        start[i] = b;
        end[i] = e;
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    auto Sit = start.begin(), Eit = end.begin();
    int ans = 0, tmp = 0;

    while (Sit != start.end()) //因為先到end的一定是start，而我們是求最大值，因此如果最後都只剩離開的話就不需計算
    {

        if (*Sit < *Eit)
        {
            tmp++;
            ++Sit;
        }
        else
        {
            tmp--;
            ++Eit;
        }

        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}