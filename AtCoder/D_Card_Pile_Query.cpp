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
vector<int> parent;

int find(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);
    vector<int> ans(N + 1, 0);

    for (int i = 0; i < Q; i++)
    {
        int C, P;
        cin >> C >> P;
        parent[C] = P;
    }

    for (int i = 1; i <= N; i++) ans[find(i)]++;
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    return 0;
}
