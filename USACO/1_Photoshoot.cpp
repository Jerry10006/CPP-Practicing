#include <iostream>
using namespace std;

//這些是我最後真的不知道怎麼解了，去找claude討論並且理解過後的解法
//將原先需要檢查翻轉的對偶位置(i和N - i)優化為不需檢查，只需要檢查當前那一組內的就好了
//e.g. HGGH 原本的方法需要檢查偶數位，則需要先翻轉第四位，翻轉前亦須檢查他的對偶位置第一位，是否為G
//但是此方法將它分為兩組[HG][GH]，不管如何翻轉只會有組的位置改變，及每一組內的兩個互換，因此可以以下列程式實現
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, reverseTime = 0;
    string cows;

    cin >> N >> cows;

    for (int i = N - 2; i >= 0; i -= 2) //將牛分成兩個一組
    {
        //i為奇數，i+1為偶數
        if (cows[i] == cows[i + 1]) continue; //若一組內的兩個一樣則不需翻轉
        if (cows[i + 1] == 'H' && cows[i] == 'G' && reverseTime % 2 == 0) reverseTime++;
        if (cows[i + 1] == 'G' && cows[i] == 'H' && reverseTime % 2 == 1) reverseTime++;
    }
    cout << reverseTime;
}

//這些是錯的
// char reverse(char type, int time)
// {
//     if (time % 2 == 0) return type;
//     else return (type == 'H') ? 'G' : 'H';
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//
//     int N, reverseTime = 0;
//     string cow;
//
//     cin >> N >> cow;
//
//     for (int i = N - 1; i >= 0; i-=2)
//     {
//         if ((reverseTime % 2 == 1 and cow[i] == 'G') or (reverseTime % 2 == 0 and cow[i] == 'H'))
//         {
//             int before = 0, after = 0;
//             for (int j = 1; j <= i; j+= 2)
//             {
//                 if (reverse(cow[j], reverseTime) == 'G') before++;
//             }
//             reverseTime++;
//             for (int j = 1; j <= i; j+= 2)
//             {
//                 if (reverse(cow[j], reverseTime) == 'G') after++;
//             }
//             if (before >= after)reverseTime--;
//         }
//     }
//     cout << reverseTime;
//     return 0;
// }