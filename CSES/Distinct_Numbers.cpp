//
// Created by 蔡杰叡 on 2025/9/17.
//
#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    ll ans = 0;
    set<int> nums;

    for (int i = 0; i < N; i++)
    {
        ll num;
        cin >> num;
        nums.insert(num);
    }

    for (auto& temp: nums)ans++;
    cout << ans;
}