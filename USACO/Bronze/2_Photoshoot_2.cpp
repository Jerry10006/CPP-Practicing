#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N, 0);
    vector<int> B(N, 0);

    for (auto& c: A) cin >> c;
    for (auto& c: B) cin >> c;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] != B[i])
        {
            auto it = find(A.begin(), A.end(), B[i]);
            int index = it - A.begin();
            rotate(A.begin() + i, A.begin() + index, A.begin() + index + 1);
            ans++;
        }
    }
    cout << ans;
}