//
// Created by 蔡杰叡 on 2025/8/28.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int N;
    fin >> N;
    int ans = 0;
    vector<vector<int>> input;

    for (int i = 0; i < N; i++)
    {
        int a, b, choose;
        fin >> a >> b >> choose;
        input.push_back({a, b, choose});
    }

    for (int i = 0; i < 3; i++)
    {
        int ans_Temp = 0;
        int play[4] = {};
        play[i + 1] = 1;
        for (size_t d = 0; d < input.size(); d++)
        {
            const vector<int> &in = input[d];
            int a = in[0], b = in[1] , c = in[2];
            swap(play[a], play[b]);
            if (play[c] == 1)
            {
                ans_Temp++;
            }
        }
        ans = max(ans, ans_Temp);
    }
    fout << ans << "\n";
}
