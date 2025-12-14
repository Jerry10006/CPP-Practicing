//
// Created by 蔡杰叡 on 2025/8/28.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("censor.in");
    ofstream fout("censor.out");

    string S, T;
    fin >> S >> T;


    vector<char> SDel;
    vector<char> TDel;

    for (size_t i = 0; i < T.size(); i++)
    {
        TDel.push_back(T[i]);
    }

    for (size_t i = 0; i < S.size(); i++)
    {
        SDel.push_back(S[i]);

        if (i > T.size() - 1)
        {
            bool IsSame = true;
            for (int a = 0; a < T.size(); a++)
            {
                if (SDel[SDel.size() - T.size() + a] != TDel[a])
                {
                    IsSame = false;
                    break;
                }
            }
            if (IsSame)
            {
                for (size_t b = 0; b < T.size(); b++)
                    SDel.pop_back();
            }
        }
    }
    for (char c : SDel)
    {
        fout << c;
    }
    fout << "\n";
}