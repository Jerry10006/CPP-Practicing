#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <set>
using namespace std;
using ll = long long;

#define pii pair<int, int>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int N = nums.size();
            int r = 0;
            vector<int> ans;
            multiset<int> SET;
            for (int l = 0; l <= N - k; l++)
            {
                while (r - l + 1 <= k)
                {
                    SET.insert(nums[r]);
                    r++;
                }

                ans.push_back(*SET.rbegin());
                SET.erase(SET.find(nums[l]));
            }
            return ans;
        }
    };
}