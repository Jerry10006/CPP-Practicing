#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_map>
using namespace std;
using ll = long long;

/*int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<tuple<char, ll, ll, bool>> cows(N);
    vector<ll> X;
    vector<ll> Y;
    unordered_map<int, int> block; //阻礙到其他牛的次數

    for (int i = 0; i < N; i++)
    {
        char direct;
        ll x, y;
        cin >> direct >> x >> y;
        cows[i] = {direct, x, y, true};
        X.push_back(x);
        Y.push_back(y);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    vector<vector<tuple<bool, int, int>>> grid(N, vector<tuple<bool, int, int>>(N, {true, 0, 0})); //true表示有草, (是否有草, 時間, 哪隻牛)

    for (int i = 0; i < N; i++)
    {
        auto& [_, x, y, exist] = cows[i];
        ll xx = lower_bound(X.begin(), X.end(), x) - X.begin();
        ll yy = lower_bound(Y.begin(), Y.end(), y) - Y.begin();

        grid[xx][yy] = {false, 0, i};
        x = xx;
        y = yy;
    }

    for (int i = 0; i < N; i++)
    {
        vector<int> del;
        for (int cow = 0; cow < N; cow++)
        {
            auto& [direct, x, y, exist] = cows[i];
            if (!exist) continue;
            if (direct == 'N')
            {
                if (x + 1 >= N) continue;
                auto& [grass, time, Cow] = grid[x + 1][y];
                if (grass)
                {
                    grass = false;
                    time = i;
                    Cow = cow;
                    x++;
                    continue;
                }

                if (i == time) //因為我發現若已經有兩隻牛同時到同一格，此格就不可能再有牛走到了，所以Cow僅記錄最後一個
                {
                    Cow = cow;
                    x++;
                    continue;
                }

                block[Cow]++;
                exist = false;
            }
            if (direct == 'E')
            {
                if (y + 1 >= N) continue;
                auto& [grass, time, Cow] = grid[x][y + 1];
                if (!exist) continue;
                if (grass)
                {
                    grass = false;
                    time = i;
                    Cow = cow;
                    y++;
                    continue;
                }

                if (i == time) //因為我發現若已經有兩隻牛同時到同一格，此格就不可能再有牛走到了，所以Cow僅記錄最後一個
                {
                    Cow = cow;
                    y++;
                    continue;
                }

                block[Cow]++;
                exist = false;
            }
        }
    }
}*/
