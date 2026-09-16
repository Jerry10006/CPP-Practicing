#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <unordered_set>
#include <set>
using namespace std;
using ll = long long;

#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N1, N2, M1, M2;
    cin >> N1 >> N2 >> M1 >> M2;
    vector<vector<int>> fadj(N1 + 1), sadj(N2 + 1);
    vector<int> fIn(N1 + 1, 0), sIn(N2 + 1, 0);
    vector<set<int>> fsteps(N1 + 1), ssteps(N2 + 1);

    for (int i = 0; i < M1; i++)
    {
        int a, b;
        cin >> a >> b;
        fadj[a].push_back(b);
        fIn[b]++;
    }
    for (int i = 0; i < M2; i++)
    {
        int a, b;
        cin >> a >> b;
        sadj[a].push_back(b);
        sIn[b]++;
    }

    queue<int> q;
    vector<int> fordered, sordered;
    for (int i = 1; i <= N1; i++) if (fIn[i] == 0)
    {
        q.push(i);
        fsteps[i].insert({0});
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        fordered.push_back(u);

        for (auto v: fadj[u])
        {
            fIn[v]--;
            if (fIn[v] == 0) q.push(v);
        }
    }
    //因為題目保證是DAG，表示q在最後必為empty，所以就不需重置
    for (int i = 1; i <= N2; i++) if (sIn[i] == 0)
    {
        q.push(i);
        ssteps[i].insert({0});
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        sordered.push_back(u);

        for (auto v: sadj[u])
        {
            sIn[v]--;
            if (sIn[v] == 0) q.push(v);
        }
    }

    vector<bool> favailable(N1 + 1, false), savailable(N2 + 1, false);
    favailable[1] = true;
    savailable[1] = true;

    for (auto u: fordered)
    {
        if (!favailable[u]) continue;
        for (auto v: fadj[u])
        {
            for (auto step: fsteps[u])
            {
                favailable[v] = true;
                fsteps[v].insert(step + 1);
            }
        }
    }

    for (auto u: sordered)
    {
        if (!savailable[u]) continue;
        for (auto v: sadj[u])
        {
            for (auto step: ssteps[u])
            {
                savailable[v] = true;
                ssteps[v].insert(step + 1);
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int a;
        cin >> a;
        bool finish = false;

        auto fit = fsteps[N1].begin(), sit = prev(ssteps[N2].end());

        while (true)
        {
            int c = *fit, d = *sit;
            if (c + d == a)
            {
                cout << "Yes" << "\n";
                finish = true;
                break;
            }

            if (c + d < a)
            {
                if (fit == prev(fsteps[N1].end())) break;
                fit = next(fit);
            }

            if (c + d > a)
            {
                if (sit == ssteps[N2].begin()) break;
                sit = prev(sit);
            }
        }

        if (!finish) cout << "No" << "\n";
    }
    return 0;
}
