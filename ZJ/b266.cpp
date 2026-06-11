#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

void rotate(vector<vector<int>>& origin)
{
    vector<vector<int>> changed(origin[0].size(), vector<int>(origin.size()));
    for (int i = 0; i < origin.size(); i++)
    {
        for (int j = 0; j < origin[0].size(); j++)
        {
            changed[origin[0].size() - j - 1][i] = origin[i][j];
        }
    }
    origin = changed;
}

void flip(vector<vector<int>>& origin)
{
    vector<vector<int>> changed(origin.size(), vector<int>(origin[0].size()));

    for (int i = 0; i < origin.size(); i++)
    {
        for (int j = 0; j < origin[0].size(); j++)
        {
            changed[origin.size() - i - 1][j] = origin[i][j];
        }
    }
    origin = changed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, M;
    cin >> R >> C >> M;
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<int> opt(M);
    for (int i = 0; i < M; i++) cin >> opt[i];

    for (int i = M - 1; i >= 0; i--)
    {
        if (!opt[i]) rotate(grid);
        else flip(grid);
    }

    cout << grid.size() << " " << grid[0].size() << "\n";
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (j == grid[0].size() - 1)
            {
                cout << grid[i][j] << "\n";
                continue;
            }
            cout << grid[i][j] << " ";
        }
    }
}
