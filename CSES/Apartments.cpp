#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> Wants(N);
    vector<int> Areas(M);
    for (auto& w: Wants) cin >> w;
    for (auto& a: Areas) cin >> a;

    sort(Wants.begin(), Wants.end());
    sort(Areas.begin(), Areas.end());

    int apartment = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        int Need = Wants[i];
        if (apartment >= M) break;
        while (Areas[apartment] <= Need + K && apartment < M)
        {
            if (Areas[apartment] >= Need - K && Areas[apartment] <= Need + K)
            {
                apartment++;
                ans++;
                break;
            }
            apartment++;
        }
    }

    cout << ans;
    return 0;
}
