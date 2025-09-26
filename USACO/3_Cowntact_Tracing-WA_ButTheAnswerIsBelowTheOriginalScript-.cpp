//
// Created by 蔡杰叡 on 2025/9/5.
//
//最下面為ChatGPT給的解答，因為其實我的結構已經差不多了，可是我原本想用回推的，但這題無法，所以只能也遍歷K，但這樣全部都要重寫，（雖然說我原本的解法也有一些地方怪怪的導致WA，但基本架構都沒問題（應該啦））
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int N, T;
    int ans_x = 0, ans_y = 1e9, ans_z = -1;
    string result; // length is N
    set<tuple<int, int, int>> set_log; // t, x, y, length is T

    cin >> N >> T >> result >> ws;

    for (int i = 0; i < T; i++)
    {
        int t, x, y;
        cin >> t >> x >> y >> ws;
        set_log.insert({t, x, y});
    }

    vector<tuple<int, int, int>> log(set_log.begin(), set_log.end());

    for (int i = 1; i <= N; i++) //暴力測試哪一個牛可能是0號病人
    {
        vector<int> simulate(N + 6);
        unordered_map<int, int> recordK;
        simulate[i] = 1;
        bool IsZero = true;
        for (int j = 0; j < T; j++)//開始模擬
        {
            auto [t, x, y] = log[j];
            if (simulate[x] == 1)
            {
                if (result[y - 1] == 0) ans_z = max(ans_z, recordK[x]);
                simulate[y] = 1;
                recordK[x]++;
                if (result[y - 1] != 1)
                {
                    IsZero = false;
                    break;
                }
            }
            else if(simulate[y] == 1)
            {
                if (result[x - 1] == 0) ans_z = max(ans_z, recordK[y]);
                simulate[x] = 1;
                recordK[y]++;
                if (result[x - 1] != 1)
                {
                    IsZero = false;
                    break;
                }
            }
        }
        for (size_t a = 0; a < N; a++)
        {
            if (result[a] != simulate[a + 1])
            {
                IsZero = false;
                break;
            }
        }
        if (IsZero)
        {
            ans_x++;
            auto min_it = min_element(recordK.begin(), recordK.end(),
    [](const auto &a, const auto &b){ return a.second < b.second; });
            ans_y = min(ans_y, min_it->second);
        }
    }

    cout << ans_x << " " << ans_y << " ";

    if (ans_z == -1) cout << "Infinity" << endl;
    else cout << ans_z << endl;
}

//以下為ChatGPT給的解答，因為其實我的結構已經差不多了，可是我原本想用回推的，但這題無法，所以只能也遍歷K，但這樣全部都要重寫，所以直接附上ChatGPT給的解答
//
// Created by 蔡杰叡 on 2025/9/5.
//

// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     freopen("tracing.in", "r", stdin);
//     freopen("tracing.out", "w", stdout);
//
//     int N, T;
//     cin >> N >> T;
//     string result;
//     cin >> result;
//
//     vector<tuple<int,int,int>> log(T);
//     for (int i = 0; i < T; i++) {
//         int t, x, y;
//         cin >> t >> x >> y;
//         log[i] = {t, x, y};
//     }
//
//     // 按時間排序
//     sort(log.begin(), log.end());
//
//     int ans_x = 0;
//     int ans_y = INT_MAX;
//     int ans_z = -1; // -1 表示Infinity
//
//     for (int i = 1; i <= N; i++) { // 假設牛 i 是零號病人
//         int minK = INT_MAX;
//         int maxK = -1;
//         for (int k = 0; k <= T; k++) { // 嘗試 K = 0..T
//             vector<int> simulate(N+1, 0);
//             vector<int> remain(N+1, 0); // 每頭牛剩下可以傳染的次數
//             simulate[i] = 1;
//             remain[i] = k;
//
//             for (auto [t,x,y] : log) {
//                 if (simulate[x] && remain[x] > 0) {
//                     if (!simulate[y]) simulate[y] = 1;
//                     remain[x]--;
//                 }
//                 if (simulate[y] && remain[y] > 0) {
//                     if (!simulate[x]) simulate[x] = 1;
//                     remain[y]--;
//                 }
//             }
//
//             bool ok = true;
//             for (int a = 1; a <= N; a++) {
//                 if (simulate[a] != (result[a-1]-'0')) {
//                     ok = false;
//                     break;
//                 }
//             }
//
//             if (ok) {
//                 minK = min(minK, k);
//                 maxK = max(maxK, k);
//             }
//         }
//
//         if (maxK != -1) { // 牛 i 可以是零號病人
//             ans_x++;
//             ans_y = min(ans_y, minK);
//             if (maxK == T) ans_z = -1; // 無上限
//             else ans_z = max(ans_z, maxK);
//         }
//     }
//
//     cout << ans_x << " " << ans_y << " ";
//     if (ans_z == -1) cout << "Infinity\n";
//     else cout << ans_z << "\n";
//
//     return 0;
// }
