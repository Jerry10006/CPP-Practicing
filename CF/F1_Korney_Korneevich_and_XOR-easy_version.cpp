#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, INF = 1e9;
    cin >> N;
    vector<int> nums(N), min_end(512, INF);
    min_end[0] = -1;
    for (auto& n: nums) cin >> n;

    for (auto n: nums)
    {
        for (int i = 0; i < 512; i++)
        {
            if (min_end[i] < n)
            {
                min_end[i ^ n] = min(min_end[i ^ n], n);
            }
        }
    }

    vector<bool> ans(512);
    int cnt = 0;
    for (int i = 0; i < 512; i++)
    {
        if (min_end[i] != INF){cnt++; ans[i] = true;}
    }

    cout << cnt << "\n";
    for (int i = 0; i < 512; i++)
    {
        if (ans[i]) cout << i << " ";
    }
    return 0;
}
