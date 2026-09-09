#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <unordered_set>
using namespace std;
using ll = long long;

int dfs(vector<int>& report, unordered_set<int>& visited, int people)
{
    if (visited.count(people)) return people;
    visited.insert(people);
    return dfs(report, visited, report[people]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> report(N + 1);
    for (int i = 1; i <= N; i++) cin >> report[i];

    for (int i = 1; i <= N; i++)
    {
        unordered_set<int> visited;
        cout << dfs(report, visited, i) << " ";
    }
    return 0;
}
