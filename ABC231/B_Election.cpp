#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    map<string, int> Count;
    for (int i = 0; i < N; i++){
        string Name;
        cin >> Name;
        Count[Name] ++;
    }
    
    auto it = max_element(Count.begin(), Count.end(), [](const auto &a, const auto &b){return a.second < b.second;});
    cout << it -> first;
}