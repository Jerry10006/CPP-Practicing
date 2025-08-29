//
// Created by 蔡杰叡 on 2025/8/28.
//
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    int ans[26] = {};

    int N;
    fin >> N;

    for (int i = 0; i < N; i++)
    {
        int countF[26] = {};
        int countS[26] = {};
        string first, second;
        fin >> first >> second;
        for (auto &ch: first)
        {
            countF[ch - 'a']++;
        }
        for (auto &ch: second)
        {
            countS[ch - 'a']++;
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            ans[ch - 'a'] += max(countF[ch - 'a'], countS[ch - 'a']);
        }
    }
    for (auto &answer: ans)
    {
        fout << answer << "\n";
    }
}