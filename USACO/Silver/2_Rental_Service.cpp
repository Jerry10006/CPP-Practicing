#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    ll N, M, R;
    cin >> N >> M >> R;

    vector<ll> cows(N), neighbor(R);
    vector<pair<ll, ll>> shops(M); //購買量, 價格

    for (auto& c: cows) cin >> c;
    for (auto& [q, p]: shops) cin >> q >> p;
    for (auto& n: neighbor) cin >> n;

    vector<pair<ll, ll>> preShops = shops; //對牛奶量做prefix，且價格為單價乘以牛奶量
    vector<ll> preNeighbor = neighbor;

    sort(preShops.begin(), preShops.end(), [](auto a, auto b)
    {
        return a.second > b.second;
    });
    sort(shops.begin(), shops.end(), [](auto a, auto b)
    {
        return a.second > b.second;
    });
    sort(preNeighbor.begin(), preNeighbor.end(), greater<ll>());
    sort(cows.begin(), cows.end());

    //之前想的不夠周到
    // for (ll i = 1; i <= M; i++)
    // {
    //     auto& [price1, number1] = preShops[i - 1];
    //     auto& [price2, number2] = preShops[i];
    //     price2 += price1;
    //     number2 += number1;
    // }

    for (ll i = 1; i < N; i++) cows[i] += cows[i - 1];
    for (ll i = 1; i < R; i++) preNeighbor[i] += preNeighbor[i - 1];
    preShops[0].second *= preShops[0].first;
    for (ll i = 1; i < M; i++)
    {
        preShops[i].second = preShops[i].second * preShops[i].first + preShops[i - 1].second;
        preShops[i].first += preShops[i - 1].first;
    }

    ll ans = 0;

    auto shopIt = lower_bound(preShops.begin(), preShops.end(), cows[N - 1], [](auto& a, auto& b){return a.first < b;});
    if (shopIt == preShops.end()) shopIt--;
    if (shopIt -> first > cows[N - 1]) ans += prev(shopIt) -> second;
    else ans += shopIt -> second;
    ll shopIndex = shopIt - preShops.begin();
    if (shopIndex == 0) ans += cows[N - 1] * shops[shopIndex].second;
    else if (preShops[shopIndex].first > cows[N - 1]) ans += (cows[N - 1] - preShops[shopIndex - 1].first) * shops[shopIndex].second;

    for (ll i = 0; i < min(N, R); i++) //要賣幾隻牛，0-based
    {
        ll tmp = 0;

        tmp += preNeighbor[i];

        ll milk = cows[N - 1] - cows[i];
        auto shopIt = lower_bound(preShops.begin(), preShops.end(), milk, [](auto& a, auto& b){return a.first < b;});
        if (shopIt == preShops.end()) shopIt--;
        if (shopIt -> first > milk) tmp += prev(shopIt) -> second;
        else tmp += shopIt -> second;
        ll shopIndex = shopIt - preShops.begin();
        if (shopIndex == 0) tmp += milk * shops[shopIndex].second;
        else if (preShops[shopIndex].first > milk) tmp += (milk - preShops[shopIndex - 1].first) * shops[shopIndex].second;

        ans = max(ans, tmp);
    }

    cout << ans;
    return 0;
}
