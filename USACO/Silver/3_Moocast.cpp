#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
using ll = long long;

struct Cow
{
    int x, y, p;
};

int distance(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void bfs(vector<Cow>& Cows, unordered_set<int>& visited, int cow, int N)
{
    deque<int> q;

    q.push_front(cow);
    visited.insert(cow);

    while (!q.empty())
    {
        int c = q.back();
        q.pop_back();

        for (int i = 0; i < N; i++)
        {
            if (i != c && distance(Cows[c].x, Cows[c].y, Cows[i].x, Cows[i].y) <= Cows[c].p * Cows[c].p && !visited.count(i))
            {
                q.push_front(i);
                visited.insert(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int N;
    cin >> N;
    vector<Cow> Cows(N);
    for (int i = 0; i < N; i++) cin >> Cows[i].x >> Cows[i].y >> Cows[i].p;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        unordered_set<int> visited;
        bfs(Cows, visited, i, N);
        ans = max(ans, static_cast<int>(visited.size()));
    }

    cout << ans;
    return 0;
}