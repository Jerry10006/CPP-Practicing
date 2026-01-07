#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K, ans = 0;
    cin >> N >> K;
    vector<int> diamond(N);
    vector<int> Best(N);
    for (auto& d: diamond) cin >> d;

    sort(diamond.begin(), diamond.end());
    int r = 0;
    for (int l = 0; l < N; l++)
    {
        while (diamond[r] - diamond[l] <= K && r < N) r++;
        Best[l] = r - l; //r是第一個不合法的index
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = i + Best[i]; j < N; j++)
        {
            ans = max(Best[i] + Best[j], ans);
        }
    }
    cout << ans;
}