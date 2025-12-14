#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> prefix_sum(N);

    for (int i = 0; i < N; i++)
    {
        ll num;
        cin >> num;
        if (i == 0) prefix_sum[i] = num;
        else prefix_sum[i] = prefix_sum[i - 1] + num;
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;

        if (l == 0) cout << prefix_sum[r - 1] << endl;
        else cout << prefix_sum[r - 1] - prefix_sum[l - 1] << endl;
    }
}