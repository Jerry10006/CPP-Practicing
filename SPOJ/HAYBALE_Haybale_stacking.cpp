#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> grass(N + 1, {0, 0});

    for (int i = 0; i < K; i++)
    {
        int begin, end;
        cin >> begin >> end;
        grass[begin].second++;
        grass[end + 1].second--;
    }

    for (int i = 1; i <= N; i++)
    {
        grass[i].first = i;
        grass[i].second += grass[i - 1].second;
    }

    sort(grass.begin(), grass.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second < b.second;
    });

    const int middle = (N + 1) / 2;
    cout << grass[middle].second;
}