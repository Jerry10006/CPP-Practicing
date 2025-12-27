#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

//太難了，最後還是決定先跳過
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> x(N), y(N), x_short(N), y_short(N);

    for (int i = 0; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;
        x[i] = X;
        x_short[i] = X;
        y[i] = Y;
        y_short[i] = Y;
    }

    sort(x_short.begin(), x_short.end());
    sort(y_short.begin(), y_short.end());
    x_short.erase(unique(x_short.begin(), x_short.end()), x_short.end());
    y_short.erase(unique(y_short.begin(), y_short.end()), y_short.end());

    vector<vector<bitset<2500>>> grid(x_short.size() + 1, vector<bitset<2500>>(y_short.size() + 1));
    vector<pair<int, int>> newPosition;
    for (int i = 0; i < N; i++)
    {
        int X = x[i], Y = y[i];
        int new_x = lower_bound(x_short.begin(), x_short.end(), X) - x_short.begin();
        int new_y = lower_bound(y_short.begin(), y_short.end(), Y) - y_short.begin();
        newPosition.push_back({new_x, new_y});
        grid[new_x + 1][new_y + 1].set(i);
    }

    for (int i = 1; i < x_short.size() + 1; i++)
    {
        for (int j = 1; j < y_short.size() + 1; j++)
        {
            grid[i][j] = grid[i][j] ^ grid[i - 1][j] ^ grid[i][j - 1] ^ grid[i - 1][j - 1];
        }
    }

    set<string> subsets;
    for (auto& p: newPosition)
    {
        for (auto& pp: newPosition)
        {
            int X = min(p.first, pp.first) + 1;
            int Y = min(p.second, pp.second) + 1;
            int XX = max(p.first, pp.first) + 1;
            int YY = max(p.second, pp.second) + 1;
            bitset<2500> bit = grid[XX][YY] ^ grid[X - 1][YY] ^ grid[XX][Y - 1] ^ grid[X - 1][Y - 1];
            subsets.insert(bit.to_string());
        }
    }
    for (auto& s : subsets) {
        bitset<2500> b(s);
        cout << "牛的數量: " << b.count() << " bitset: " << s.substr(2496, 4) << endl;
    }
    cout << subsets.size() + 1;
    return 0;
}