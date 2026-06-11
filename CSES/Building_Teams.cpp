#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

bool dfs(vector<vector<int>>& friends, vector<int>& teams, set<int>& visited, int person, int team)
{
    visited.insert(person);
    if (teams[person] == 0) teams[person] = team;
    for (auto p: friends[person])
    {
        if (teams[p] == teams[person]) return false;
        else if (!visited.count(p)) if (!dfs(friends, teams, visited, p, team * -1)) return false;;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> friends(n + 1);
    vector<int> teams(n + 1, 0);
    set<int> visited;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited.count(i)) if (!dfs(friends, teams, visited, i, 1))
        {
            cout << "IMPOSSIBLE";
            return 0;
        };
    }

    for (int i = 1; i <= n; i++)
    {
        if (teams[i] == -1) teams[i] = 2;
        cout << teams[i] << " ";
    }
    return 0;
}
