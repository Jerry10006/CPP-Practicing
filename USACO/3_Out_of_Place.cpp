#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int N;
    string position;
    vector<int> cows;
    vector<int> Temp;
    int Wrong;
    vector<int>::iterator WrongIt;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int Cow;
        cin >> Cow;
        cows.push_back(Cow);
    }
    for (int i = 1; i < N; i++) //看錯誤的是在前還是在後，以及記錄下來
    {
        if (cows[i] < cows[i - 1])
        {
            position = "front";
            Wrong = cows[i];
            WrongIt = cows.begin() + i;
            break;
        }
        if (i + 2 < N)
        {
            if (cows[i] > cows[i + 1] && cows[i] > cows[i + 2])
            {
                position = "back";
                Wrong = cows[i];
                WrongIt = cows.begin() + i;
                break;
            }
        }
    }
    vector<int> sortedCows = cows;
    sort(sortedCows.begin(), sortedCows.end());
    auto it = find(sortedCows.begin(), sortedCows.end(), Wrong);//找到再以排序的牛裡面，原先錯誤的牛應該在哪
    if (position == "front")
    {
        while (*next(it) == *it) ++it; //為了計算正確，我們將it移到最接近未排序時，錯誤的牛的地方
        Temp.assign(cows.begin() + (it - sortedCows.begin()), WrongIt); //將在原本的牛中應該在的位置一直到目前錯誤的牛的位置複製下來(不包含自己)
    }
    else if (position == "back")
    {
        while (*prev(it) == *it) --it; //為了計算正確，我們將it移到最接近未排序時，錯誤的牛的地方
        Temp.assign(next(WrongIt), cows.begin() + (it - sortedCows.begin()) + 1); //將在原本的牛中應該在的位置一直到目前錯誤的牛的位置複製下來(不包含自己)
    }

    unordered_set<int> different(Temp.begin(), Temp.end()); //去重

    cout << different.size();
}