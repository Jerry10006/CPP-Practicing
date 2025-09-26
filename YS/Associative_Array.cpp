//
// Created by 蔡杰叡 on 2025/9/20.
//
#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll Q;
    cin >> Q;
    map<ll, ll> a;

    for (int i = 0; i < Q; i++)
    {
        ll type, k;
        cin >> type;

        if (!type)
        {
            ll v;
            cin >> k >> v;
            a[k] = v;
        }
        else
        {
            cin >> k;
            cout << a[k] << endl;
        }
    }
}