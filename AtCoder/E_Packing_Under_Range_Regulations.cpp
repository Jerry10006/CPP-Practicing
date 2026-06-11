#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

bool check()
{
    int N;
    cin >> N;
    vector<pair<int, int>> lim(N);
    for (int j = 0; j < N; j++)
    {
        cin >> lim[j].first >> lim[j].second;
    }

    sort(lim.begin(), lim.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> left; //end, begin

    int ball_idx = 0, box_idx = 0;
    while (ball_idx < N || !left.empty())
    {
        if (left.empty())
        {
            box_idx = max(box_idx, lim[ball_idx].first);
        }
        while (ball_idx < N && lim[ball_idx].first <= box_idx)
        {
            left.push({lim[ball_idx].second, lim[ball_idx].first});
            ball_idx++;
        }

        int idx = left.top().first;
        if (idx < box_idx) return false;
        box_idx++;
        left.pop();
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        if (check()) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}