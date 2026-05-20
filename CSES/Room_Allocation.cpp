#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<tuple<int, int, int>> time(N);
    vector<int> No_vector(N);

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        time[i] = {start, end, i};
    }

    sort(time.begin(), time.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //退房時間/編號

    int Number = 1;
    for (auto [start, end, No]: time)
    {
        if (pq.empty() || pq.top().first >= start)
        {
            pq.push({end, Number});
            No_vector[No] = Number;
            Number++;
        }
        else
        {
            int Num = pq.top().second;
            pq.pop();
            No_vector[No] = Num;
            pq.push({end, Num});
        }
    }

    cout << Number - 1 << "\n";
    for (auto num: No_vector)
    {
        cout << num << " ";
    }
    return 0;
}
