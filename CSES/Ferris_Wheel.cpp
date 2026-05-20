//以後遇到類似的問題記得一定要sort!!!然後還要記得先算出可以成功配對的組數，再用全部人數剪掉組數（省下的）就好了
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    vector<int> weight(N);
    for (auto& g: weight) cin >> g;

    sort(weight.begin(), weight.end());

    int lighter = 0, heavier = N - 1, pair = 0;

    while (lighter < heavier)
    {
        if (weight[lighter] + weight[heavier] <= X)
        {
            lighter++;
            heavier--;
            pair++;
        }
        else
        {
            heavier--;
        }
    }

    cout << N - pair;
}
