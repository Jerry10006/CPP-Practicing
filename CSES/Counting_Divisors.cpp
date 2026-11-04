#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
using namespace std;
using ll = long long;

#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        ll cnt = 0;
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                if (j == x / j) cnt++;
                else cnt += 2;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
