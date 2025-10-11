//
// Created by 蔡杰叡 on 2025/9/26.
//
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int N;
    cin >> N;
    unordered_map<string, int> milk;
    const vector<string> name = {"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};
    map<int, vector<string>> sorted;
    for (auto& n: name) milk[n] = 0;

    for (int i = 0; i < N; i++)
    {
        string Name;
        int Milk;
        cin >> Name >> Milk;
        milk[Name] += Milk;
    }

    for (const auto& m: milk)
    {
        sorted[m.second].push_back(m.first);
    }

    auto it = sorted.begin();
    ++it;
    if (it == sorted.end()) {
        cout << "Tie";
        return 0;
    }
    auto Name = it->second;
    if (Name.size() > 1) cout << "Tie";
    else cout << Name[0];
    return 0;
}