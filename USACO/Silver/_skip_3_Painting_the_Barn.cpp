#include <iostream>
using namespace std;

void debug(int grid[202][202])
{
    for (int i = 0; i < 202; i++)
    {
        for (int j = 0; j < 202; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int grid[202][202] = {};
    int value[202][202] = {};
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        grid[x1][y1]++;
        grid[x2][y2]++;
        grid[x1][y2]--;
        grid[x2][y1]--;
    }

    for (int i = 1; i < 201; i++) for (int j = 1; j < 201; j++) grid[i][j] += grid[i][j - 1];
    for (int j = 1; j < 201; j++) for (int i = 1; i < 201; i++) grid[i][j] += grid[i - 1][j]; //如果變成[x1, x2], [y1, y2]，這邊也要改(199->200)(201->202)
    debug(grid);

    for (int i = 0; i < 202; i++)
    {
        for (int j = 0; j < 202; j++)
        {
            if (grid[i][j] == K - 1) value[i][j] = 1;
            if (grid[i][j] == K) value[i][j] = -1;
        }
    }


}