#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <chrono>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    struct custom_hash
    {
        static uint64_t splitmix64(uint64_t x)
        {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const
        {
            static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    int N;
    cin >> N;
    vector<int> nums(N);
    for (auto& n: nums) cin >> n;
    unordered_map<int, int, custom_hash> times;

    for (auto n: nums)
    {
        times[n] = max(times[n], times[n - 1] + 1);
    }

    int ans = 0, end = 0;
    for (auto& [num, length]: times)
    {
        if (length > ans)
        {
            ans = length;
            end = num;
        }
    }
    cout << ans << "\n";

    int next = end - ans + 1;
    for (int i = 0; i < N; i++)
    {
        if (nums[i] == next)
        {
            cout << i + 1 << " ";
            next++;
        }
    }
    return 0;
}
