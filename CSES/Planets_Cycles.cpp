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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> tele(N + 1), indeg(N + 1, 0), rev();
    for (int i = 1; i <= N; i++)
    {
        int tag;
        cin >> tag;
        indeg[tag]++;
        tele[i] = tag;
    }




}
