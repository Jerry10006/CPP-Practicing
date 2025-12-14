#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    vector<vector<int>> graph(2001, vector<int>(2001, -1)); //以row當x, colum當y, 所以為graph[x][y]的形式,1為割草機廣告,0為飼料廣告
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
    {
        for (int j = y1; j < y2; j++) graph[i + 1000][j + 1000] = 1;
    }

    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
    {
        for (int j = y1; j < y2; j++) graph[i + 1000][j + 1000] = 0;
    }

    int x_length = 0, y_length = 0;
    bool Xplus = false;
    int min_x = 1e9, min_y = 1e9, max_x = -1, max_y = -1;
    int ans = 0;
    for (int i = 0; i < 2001; i++)
    {
        int y_tmp = 0;
        for (int j = 0; j < 2001; j++)
        {
            if (graph[i][j] == 1)
            {
                min_x = min(min_x, i);
                min_y = min(min_y, j);
                max_x = max(max_x, i);
                max_y = max(max_y, j);
                ans++;
            }
        }
    }
    if (max_x == -1) cout << 0;
    else cout << (max_x - min_x + 1) * (max_y - min_y + 1);
}