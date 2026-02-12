#include <iostream>
using namespace std;

int main()
{
    int n, t, k;
    cin >> n >> t >> k; // t always = 1

    int low = 1, high = n, ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        cout << "? 1 " << mid << endl;

        int sum;
        cin >> sum;

        int CountZero = mid - sum;

        if (CountZero >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "! " << ans << endl;

    return 0;
}
