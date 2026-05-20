#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> str(N);

    for (auto& s: str) cin >> s;
    sort(str.begin(), str.end(), [](auto& a, auto& b){return a + b < b + a;});

    for (auto& s: str) cout << s;
    return 0;
}
