#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Node
{
    int x, y, t;
};

bool distance(Node C, Node F)
{
    ll dx = C.x - F.x;
    ll dy = C.y - F.y;
    ll dt = C.t - F.t;
    if (dx * dx + dy * dy > dt * dt) return false;
    else return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int G, N, ans = 0;
    cin >> G >> N;
    vector<Node> farm(G);
    vector<Node> cow(N);

    for (auto& f: farm) cin >> f.x >> f.y >> f.t;
    for (auto& c: cow) cin >> c.x >> c.y >> c.t;

    sort(farm.begin(), farm.end(), [](Node a, Node b){return a.t < b.t;});
    sort(cow.begin(), cow.end(), [](Node a, Node b){return a.t < b.t;});

    for (auto c: cow)
    {
        auto target = lower_bound(farm.begin(), farm.end(), c, [](Node a, Node b){return a.t < b.t;});
        auto targetp = (target != farm.begin() ? prev(target) : target);
        if (target == farm.end()) target = prev(target);
        if (!distance(c, *target) || !distance(c, *targetp)) ans++;
    }
    cout << ans;
}
