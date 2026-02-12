#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool check(int N, int M, ll D, vector<ll>& beginning, vector<ll>& end)
{
    int count = 1;
    int chunk = 0;
    ll nowPos = beginning[0];

    for (int i = 1; i < N; i++)
    {
        ll nextPossible = nowPos + D;

        while (chunk < M && nextPossible > end[chunk]) chunk++;

        if (chunk == M) return false;

        nowPos = max(nextPossible, beginning[chunk]);
        count++;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<ll> beginning(M);
    vector<ll> end(M);

    for (int i = 0; i < M; i++)
    {
        ll a, b;
        cin >> a >> b;
        beginning[i] = a;
        end[i] = b;
    }

    sort(beginning.begin(), beginning.end());
    sort(end.begin(), end.end());

    ll low = 0, high = 1e18 + 7, ans = 0;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(N, M, mid, beginning, end))
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << ans;
}
