#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    vector<int> time(N);

    for (auto& t: time) cin >> t;
    sort(time.begin(), time.end());

    int now = 0;
    for (int i = 0; i < N; i++)
    {
        now += time[i];
        if (now > X)
        {
            cout << i;
            return 0;
        }
    }
    cout << N;
    return 0;
}
