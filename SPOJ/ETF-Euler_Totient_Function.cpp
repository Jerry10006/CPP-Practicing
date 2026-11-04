#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> phi(1e6 + 7);
    iota(phi.begin(), phi.end(), 0);

    for (int i = 2; i <= 1e6; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= 1e6; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }

    for (int t = 0; t < T; t++)
    {
        int x;
        cin >> x;
        cout << phi[x] << "\n";
    }
    return 0;
}
