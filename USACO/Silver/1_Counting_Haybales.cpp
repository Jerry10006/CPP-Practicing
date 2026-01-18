#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;
    vector<int> grass(N);

    for (auto& g: grass) cin >> g;
    sort(grass.begin(), grass.end());

    for (int i = 0; i < Q; i++)
    {
        int b, e;
        cin >> b >> e;

        cout << upper_bound(grass.begin(), grass.end(), e) - lower_bound(grass.begin(), grass.end(), b) << "\n"; //剛好+1 -1抵銷
    }
    return 0;
}
