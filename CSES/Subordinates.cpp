#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

vector<int> cnt(2e5 + 5);
vector<vector<int>> graph(2e5 + 5);

int dfs(int person)
{
    for (auto& p: graph[person])
    {
        cnt[person] += dfs(p);
    }
    return cnt[person] + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        int up;
        cin >> up;
        graph[up].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= N; i++) cout << cnt[i] << " ";
    return 0;
}
