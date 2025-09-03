#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    pair<int, int> position[N];
    int ans = 0;
    int minX = 0, minY = 0, maxX = 0, maxY = 0; 

    for (auto &p: position) cin >> p.first;
    for (auto &p: position) cin >> p.second;
    
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            int dx = position[i].first - position[j].first;
            int dy = position[i].second - position[j].second;
            ans = max(ans, dx * dx + dy * dy);
        }
    }
    cout << ans << endl;
}