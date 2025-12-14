//
// Created by 蔡杰叡 on 2025/10/11.
//

//此題我題目沒看清楚，方向全錯，但因為此題過於困難，所以先跳過
#include <iostream>
using namespace std;

int distance(int n) //算距離，n為時間
{
    return (n * n - n) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, N; //K為距離，N為有幾個X
    cin >> K >> N;

    for (int i = 0; i < N; i++)
    {
        int X; //最大速度
        cin >> X;
        int nMax = X, nMin = 1, n = (nMax + nMin) / 2; //時間
        int currentDistance = 0, prevDistance = 0;
        do
        {
            if (nMin <= X) //目前n就等於速度，所以若最小速度>最大速度，則需要減少
            {
                currentDistance = distance(n);
                prevDistance = distance(n - 1);
                if (currentDistance > K && prevDistance > K)
                {
                    nMax = n - 1;
                }
                else if (currentDistance < K)
                {
                    nMin = n + 1;
                }

                n = (nMax + nMin) / 2;
            }
            else
            {
                n = nMin;
                break;
            }
        }
        while (not (currentDistance >= K && prevDistance < K));

        if (currentDistance >= K && prevDistance < K)
        {
            cout << n << endl;
            continue;
        }

        const int leftDistance = K - currentDistance; //剩餘多少距離
        n += 2 * (int)(leftDistance / 2 * X + 1); //2 * X + 1表示的是加速和減速各一次的距離
        if (leftDistance - (int)(leftDistance / 2 * X + 1) > X) n += 2;
        else n++;
        cout << n << endl;
    }
}