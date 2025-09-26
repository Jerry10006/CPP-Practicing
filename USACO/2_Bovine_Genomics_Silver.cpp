//
// Created by 蔡杰叡 on 2025/9/5.
//
#include <iostream>
#include <set>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M, ans = 0;
    cin >> N >> M;
    vector<string> Spot(N + 5);
    vector<string> NonSpot(N + 5);


    for (int i = 0; i < N; i++)
    {
        string Temp;
        cin >> Temp;
        Spot[i] = Temp;
    }
    for (int i = 0; i < N; i++)
    {
        string Temp;
        cin >> Temp;
        NonSpot[i] = Temp;
    }

    for (int i = 0; i < M - 2; i++)
    {
        for (int j = i + 1; j < M - 1; j++)
        {
            for(int k = j + 1; k < M; k++)
            {
                set<string> SpotSet;
                set<string> NonSpotSet;

                for (int a = 0; a < N; a++)
                {
                    string Temp = "";
                    Temp += Spot[a][i];
                    Temp += Spot[a][j];
                    Temp += Spot[a][k];
                    SpotSet.insert(Temp);
                }
                for (int a = 0; a < N; a++)
                {
                    string Temp = "";
                    Temp += NonSpot[a][i];
                    Temp += NonSpot[a][j];
                    Temp += NonSpot[a][k];
                    NonSpotSet.insert(Temp);
                }
                bool Repeat = false;
                for (auto &SpotS: SpotSet)
                {
                    if (NonSpotSet.count(SpotS))
                    {
                        Repeat = true;
                        break;
                    }
                }
                if (!Repeat) ans++;
            }
        }
    }
    cout << ans;
}