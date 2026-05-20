#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int N;
    cin >> N;
    vector<tuple<int, int ,int>> Cows; //arrive, priority, eating;
    priority_queue<int, vector<int>, greater<>> time;

    for (int i = 1; i <= N; i++)
    {
        int arrive, eating;
        cin >> arrive >> eating;
        Cows.push_back({arrive, i, eating});
        time.push(arrive);
    }

    sort(Cows.begin(), Cows.end());
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Now; //priority, arrive, eating

    int i = 0, current = 0, ans = 0;
    while (i < N || !Now.empty())
    {
        if (Now.empty() && current < get<0>(Cows[i]))
        {
            current = get<0>(Cows[i]);
        }

        while (i < N && get<0>(Cows[i]) <= current)
        {
            auto [arrive, priority, eating] = Cows[i];
            Now.push({priority, arrive, eating});
            i++;
        }

        if (!Now.empty())
        {
            auto [priority, arrive, eating] = Now.top();
            Now.pop();

            ans = max(ans, current - arrive);
            current += eating;
        }
    }
    cout << ans;
}
