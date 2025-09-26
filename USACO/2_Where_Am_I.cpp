//
// Created by 蔡杰叡 on 2025/9/20.
//
#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    ll N;
    string color;
    queue<char> ans;
    cin >> N;
    cin >> color;

    for (int k = 1; k <= N; k++)
    {
        set<string> repeat;
        bool Repeat = false;
        for (int i = 0; i < N - (k - 1); i++)
        {
            string Temp = color.substr(i, k);
            if (repeat.count(Temp)){
                Repeat = true;
                break;
            }
            else repeat.insert(Temp);
        }
        if (!Repeat)
        {
            cout << k;
            return 0;
        }
    }
}