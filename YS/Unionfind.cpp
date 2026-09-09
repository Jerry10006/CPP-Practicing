#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU
{
    vector<int> parent, sz;

    DSU(int N)
    {
        parent.resize(N + 1);
        sz.resize(N + 1, 1);
        for (int i = 0; i <= N; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }

    bool unite(int a, int b)
    {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB)
            return false;

        if (sz[rootA] < sz[rootB])
            swap(rootA, rootB);
        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];
        return true;
    }

    bool same(int a, int b)
    {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB)
            return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    DSU dsu(N);

    for (int i = 0; i < Q; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0)
        {
            dsu.unite(u, v);
        }

        if (t == 1)
        {
            if (dsu.same(u, v))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
    return 0;
}