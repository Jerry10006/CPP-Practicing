#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pii pair<int, int>
#define pic pair<int, char>
#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<pic>> adj(N + 1);

    for (int i = 0; i < M; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    queue<pii> q;
    vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, false));
    q.push({1, N});
    int length = 0;

    vis[1][N] = true;

    int ans = 1e9;

    while (!q.empty()){
        length++;
        int sz = q.size();
        for (int i = 0; i < sz; i++){
            auto [a, b] = q.front();
            q.pop();

            for (auto [x, sign]: adj[a]){
                for (auto [y, SIGN]: adj[b]){
                    if (sign == SIGN){
                        if (x == b && a == y){
                            ans = min(ans, length * 2 - 1);
                        }   
                        if (x == y){
                            ans = min(ans, length * 2);
                        }

                        if (vis[x][y]) continue;
                        q.push({x, y});
                        vis[x][y] = true;
                    }
                }
            }
        }
        if (ans != 1e9){ 
                cout << ans;
                return 0;
            }
    }

    cout << -1;
    return 0;
}