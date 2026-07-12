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
    vector<int> POS(N + 1);//A陣列每個數字對應的位置
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        POS[tmp] = i;
    }

    vector<int> pos(N);//B陣列數字對應POS的編號
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        pos[i] = POS[tmp];
    }

    vector<int> LIS;
    for (int i = 0; i < N; i++)
    {
        int pos1 = lower_bound(LIS.begin(), LIS.end(), pos[i]) - LIS.begin();
        if (pos1 == LIS.size()) LIS.push_back(pos[i]);
        else LIS[pos1] = pos[i];
    }

    cout << LIS.size();
    return 0;
}
