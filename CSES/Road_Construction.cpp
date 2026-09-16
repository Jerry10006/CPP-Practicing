#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
using namespace std;
using ll = long long;

#define pii pair<int, int>

struct DSU
{
    vector<int> parent, sz;
    DSU(int N)
    {
        parent.resize(N + 1);
        sz.resize(N + 1, 1);
        for (int i = 0; i <= N; i++) parent[i] = i;
    }

    int find(int a)
    {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    bool unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (sz[a] < sz[b])  swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same(int a, int b)
    {
        a = find(a), b = find(b);
        return a == b;
    }
    int size(int a)
    {
        return sz[find(a)];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    DSU dsu(N);
    int connected = N, maxSize = 1;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        if (dsu.same(a, b))
        {
            cout << connected << " " << maxSize << "\n";
            continue;
        }
        dsu.unite(a, b);
        connected--;
        maxSize = max({dsu.size(a), dsu.size(b), maxSize});
        cout << connected << " " << maxSize << "\n";
    }
}
