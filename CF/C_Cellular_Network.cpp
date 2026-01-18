#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> cities(n);
    vector<ll> cellulars(m);

    for (auto& city: cities) cin >> city;
    for (auto& cellular: cellulars) cin >> cellular;

    ll cellularP = 0;
    for (ll citiesP = 0; citiesP < n; citiesP++)
    {
        while (cellularP < m - 1 && abs(cities[citiesP] - cellulars[cellularP]) >= abs(cities[citiesP] - cellulars[cellularP + 1])) cellularP++;
        ans = max(ans, abs(cities[citiesP] - cellulars[cellularP]));
    }
    cout << ans;
}