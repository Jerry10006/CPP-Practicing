#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

struct DSU
{
    vector<int> parent;

    DSU(int N)
    {
        parent.resize(N + 1);
        for (int i = 1; i <= N; i++) parent[i] = i;
    }

    int find(int v)
    {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b)
    {
        int a_root = find(a);
        int b_root = find(b);
        if (a_root == b_root) return false;
        parent[b_root] = a_root;
        return true;
    }

    bool same(int a, int b)
    {
        int a_root = find(a);
        int b_root = find(b);
        if (a_root == b_root) return true;
        return false;
    }
};

bool check(int width, vector<int>& pos, vector<vector<pair<int, int>>>& connect, int N)
{
    DSU dsu(N);

    for (int i = 1; i <= N; i++)
    {
        for (auto& [arrive, w]: connect[i])
        {
            if (w >= width) dsu.unite(i, arrive);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (!dsu.same(pos[i], i)) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<int> pos(N + 1);
    vector<vector<pair<int, int>>> connect(N + 1); //connect[start] = arrive/width
    for (int i = 1; i <= N; i++) cin >> pos[i];
    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        connect[a].push_back({b, w});
        connect[b].push_back({a, w});
    }

    bool allSame = true;
    for (int i = 1; i <= N; i++)
    {
        if (pos[i] != i) allSame = false;
    }
    if (allSame)
    {
        cout << -1;
        return 0;
    }

    int low = 1, high = 1e9, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid, pos, connect, N))
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << ans;
    return 0;
}
