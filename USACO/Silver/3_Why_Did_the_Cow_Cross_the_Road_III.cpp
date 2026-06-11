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

    int N, K, R;
    cin >> N >> K >> R;

    bool road[105][105][105][105];
    for (int i = 0; i < R; i++)
    {
        int r, c, r1, c1;
        cin >> r >> c >> r1 >> c1;
        road[r][c][r1][c1] = true;
    }
    vector<vector<bool>> cow(N, vector<bool>(N));
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        cow[r][c] = true;
    }

    

}
