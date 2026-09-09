#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> row(N + 1, -1), col(N + 1, -1); //這一列/欄上的棋子在哪一欄/列
    int ans = 0;

    for (int i = 0; i < M; i++)
    {
        int R, C;
        cin >> R >> C;
        if (row[R] != -1)
        {
            ans--;
            col[row[R]] = -1;
        }
        if (col[C] != -1)
        {
            ans--;
            row[col[C]] = -1;
        }
        ans++;
        row[R] = C;
        col[C] = R;
    }

    cout << ans;
    return 0;
}
