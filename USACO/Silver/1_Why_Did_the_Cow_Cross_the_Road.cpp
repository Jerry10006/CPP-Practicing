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

    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    
    ll C, N;
    cin >> C >> N;
    vector<ll> Chickens(C);
    vector<pair<ll, ll>> Cows(N);

    for (ll i = 0; i < C; i++)
    {
        cin >> Chickens[i];
    }
    for (ll i = 0; i < N; i++)
    {
        cin >> Cows[i].first >> Cows[i].second;
    }

    sort(Chickens.begin(), Chickens.end());
    sort(Cows.begin(), Cows.end());

    ll cow = 0, chicken = 0, ans = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Remaining; //end, begin
    while (chicken < C && (cow < N || !Remaining.empty()))
    {
        if (Remaining.empty())
        {
            Remaining.push({Cows[cow].second, Cows[cow].first});
            while (chicken < C && Cows[cow].first > Chickens[chicken]) chicken++;
            cow++;
        }

        while (cow < N && Cows[cow].first <= Chickens[chicken])
        {
            Remaining.push({Cows[cow].second, Cows[cow].first});
            cow++;
        }

        ll earliestCow = Remaining.top().first;
        if (earliestCow >= Chickens[chicken])
        {
            chicken++;
            ans++;
        }
        Remaining.pop();
    }

    cout << ans;
}