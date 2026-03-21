#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<ll, ll>> cows(N);
    vector<pair<ll, ll>> leftY(N, {8e18, 0}), rightY(N, {8e18, 0}), leftX(N, {8e18, 0}), rightX(N, {8e18, 0}); // min/ max
    ll MinX, MaxX, MinY, MaxY;

    for (auto& [x, y]: cows)
    {
        cin >> x >> y;
    }

    vector<pair<ll, ll>> Ycows = cows;
    sort(cows.begin(), cows.end());
    MinX = cows[0].first, MaxX = cows[N - 1].first;

    leftY[0] = {cows[0].second, cows[0].second}, rightY[N - 1] = {cows[N - 1].second, cows[N - 1].second};
    for (int i = 1; i < N; i++)
    {
        auto [x1, y1] = cows[i];
        auto [x2, y2] = cows[(N - 1) - i];
        leftY[i].first = min(leftY[i - 1].first, y1);
        leftY[i].second = max(leftY[i - 1].second, y1);
        rightY[(N - 1) - i ].first = min(rightY[(N - 1 - i) + 1].first, y2);
        rightY[(N - 1) - i ].second = max(rightY[(N - 1 - i) + 1].second, y2);
    }


    sort(Ycows.begin(), Ycows.end(), [](auto& a, auto& b)
    {
        if (a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });

    MinY = Ycows[0].second, MaxY = Ycows[N - 1].second;
    leftX[0] = {Ycows[0].first, Ycows[0].first}, rightX[0] = {Ycows[N - 1].first, Ycows[N - 1].first};
    for (int i = 1; i < N; i++)
    {
        auto [x1, y1] = Ycows[i];
        auto [x2, y2] = Ycows[(N - 1) - i];
        leftX[i].first = min(leftX[i - 1].first, x1);
        leftX[i].second = max(leftX[i - 1].second, x1);
        rightX[(N - 1) - i ].first = min(rightX[(N - 1 - i) + 1].first, x2);
        rightX[(N - 1) - i ].second = max(rightX[(N - 1 - i) + 1].second, x2);
    }

    ll MinSquare = 8e18;
    for (int i = 0; i < N - 1; i++)
    {
        if (cows[i].first == cows[i+1].first) continue;
        ll a1 = (cows[i].first - cows[0].first) * (leftY[i].second - leftY[i].first);
        ll a2 = (cows[N-1].first - cows[i+1].first) * (rightY[i+1].second - rightY[i+1].first);
        MinSquare = min(MinSquare, a1 + a2);
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (Ycows[i].second == Ycows[i+1].second) continue;
        ll a1 = (Ycows[i].second - Ycows[0].second) * (leftX[i].second - leftX[i].first);
        ll a2 = (Ycows[N-1].second - Ycows[i+1].second) * (rightX[i+1].second - rightX[i+1].first);
        MinSquare = min(MinSquare, a1 + a2);
    }

    cout << (MaxX - MinX) * (MaxY - MinY) - MinSquare;
    return 0;
}