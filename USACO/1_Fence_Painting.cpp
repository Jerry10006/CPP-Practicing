//
// Created by 蔡杰叡 on 2025/10/7.
//
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (c > b || d < a) cout << (b - a) + (d - c);
    else cout << max(max(a, b), max(c, d)) - min(min(a, b), min(c, d));
    return 0;
}