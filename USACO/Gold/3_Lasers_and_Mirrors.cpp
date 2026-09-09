#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using ll = long long;
using namespace std;

#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

vector<pii> dire = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct POS{
    ll X, Y, length;
};

struct direction{
    int dx, dy;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, xl, yl, xb, yb;
    cin >> N >> xl >> yl >> xb >> yb;

    vector<pii> pos;
    vector<int> x, y;

    x.push_back(xl);
    x.push_back(xb);
    y.push_back(yl);
    y.push_back(yb);

    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        pos.push_back({a, b});
        x.push_back(a);
        y.push_back(b);
    }

    sort(all(x));
    sort(all(y));

    x.erase(unique(all(x)), x.end());
    y.erase(unique(all(y)), y.end());
    
    POS start, stop;
    start = {lower_bound(all(x), xl) - x.begin(), lower_bound(all(y), yl) - y.begin(), 0};
    stop = {lower_bound(all(x), xb) - x.begin(), lower_bound(all(y), yb) - y.begin(), 0};

    vector<vector<bool>> grid(x.size(), vector<bool>(y.size(), false)), vis(x.size(), vector<bool>(y.size(), false));

    for (auto& [xx, yy]: pos){
        xx = lower_bound(all(x), xx) - x.begin();
        yy = lower_bound(all(y), yy) - y.begin();

        grid[xx][yy] = true;
    }

    deque<pair<POS, direction>> q;

    for (auto [dx, dy]: dire){
        if (start.X + dx >= 0 && start.X + dx < x.size() && start.Y >= 0 && start.Y < y.size()) q.push_front({start, {dx, dy}});
    }

    while (!q.empty()){
        pair<POS, direction> now = q.front();
        q.pop_front();
    
        auto [Pos, DIRE] = now;
        auto [x, y, length] = Pos;
        auto [ddx, ddy] = DIRE;

        if (x == start.X && y == start.Y){
            cout << length;
            return 0;
        }

        for (auto& [dx, dy]: dire){
            int xx = x + dx, yy = y + dy;
            if (!grid[xx][yy]) continue;
            if (vis[xx][yy]) continue;

            vis[xx][yy] = true;
            if ((dx != 0 && ddx != 0) || (dy != 0 && ddy != 0)){
                q.push_front({{xx, yy, length}, {dx, dy}});
            }
            if ((dx != 0 && ddx == 0) || (dy != 0 && ddy == 0) || (dx == 0 && ddy != 0) || (dy == 0 && ddy != 0)){
                q.push_back({{xx, yy, length}, {dx, dy}});
            }
        }
    }

    cout << -1;
    return 0;
}