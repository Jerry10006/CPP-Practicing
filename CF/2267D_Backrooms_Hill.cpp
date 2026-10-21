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

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<int> parity(N + 1);
        for (int i = 1; i <= N; i++)
        {
            int x;
            cin >> x;
            parity[x] = i % 2;
        }

        int l = 1, r = N;
        bool end = true;
        for (int i = 1; i <= N; i++)
        {
            if (l % 2 == parity[i]) l++;
            else if (r % 2 == parity[i]) r--;
            else
            {
                end = false;
                break;
            }
        }

        cout << (end? "Yes": "No") << "\n";
    }
    return 0;
}
