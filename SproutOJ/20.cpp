//
// Created by 蔡杰叡 on 2025/8/24.
//
#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    list<int> Player;
    list<int>::iterator node_it[n + 6];
    for (int i = 1; i <= n; i++)
    {
        Player.push_back(i);
        node_it[i] = prev(Player.end());
    }
    for (int i = 0; i < m; i++)
    {
        int type, player;
        cin >> type >> player;
        if (node_it[player] != Player.end())
        {
            if (type == 0)
            {
                Player.erase(node_it[player]);
                node_it[player] = Player.end();
            }
            else
            {
                auto player_it = (node_it[player] == Player.begin() ? Player.begin() : prev(node_it[player]));
                Player.splice(player_it, Player, node_it[player]);
            }
        }
    }

    while (Player.size())
    {
        if (Player.size() == 1)
        {
            cout << Player.front() << endl;
            Player.pop_front();
        }
        else
        {
            cout << Player.front() << " ";
            Player.pop_front();
        }
    }
}