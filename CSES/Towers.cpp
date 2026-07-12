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

    int N;
    cin >> N;
    vector<int> blocks(N);
    for (auto& b: blocks) cin >> b;
    vector<int> LIS;

    for (int i = 0; i < N; i++)
    {
        int pos = upper_bound(LIS.begin(), LIS.end(), blocks[i]) - LIS.begin();
        if (pos == LIS.size()) LIS.push_back(blocks[i]);
        else LIS[pos] = blocks[i];
    }

    cout << LIS.size();
    return 0;
}
