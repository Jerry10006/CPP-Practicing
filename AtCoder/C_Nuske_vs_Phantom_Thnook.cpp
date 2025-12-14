#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> grid(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> row(N + 1, vector<int>(M + 1, 0)); //橫列是否連通
    vector<vector<int>> column(N + 1, vector<int>(M + 1, 0)); //豎列是否連通

    for (int i = 1; i <= N; i++)
    {
        string row_s;
        cin >> row_s;
        for (int j = 1; j <= M; j++)
        {
            grid[i][j] = row_s[j - 1] - '0';
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= M; j++) if (grid[i][j - 1] == 1 && grid[i][j] == 1) row[i][j] = 1;
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= M; j++) if (grid[i - 1][j] == 1 && grid[i][j] == 1) column[i][j] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            row[i][j] += row[i - 1][j] + row[i][j - 1] - row[i -1][j - 1];
            column[i][j] += column[i - 1][j] + column[i][j - 1] - column[i -1][j - 1];
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i -1][j - 1];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 他的x是列，y是行，不是座標！！！
        const int node = grid[x2][y2] - grid[x1 - 1][y2] - grid[x2][y1 - 1] + grid[x1 - 1][y1 - 1];
        const int edge = (row[x2][y2] - row[x1 - 1][y2] - row[x2][y1] + row[x1 - 1][y1]) + (column[x2][y2] - column[x1][y2] - column[x2][y1 - 1] + column[x1][y1 - 1]);
        cout << node - edge << endl;
    }
}