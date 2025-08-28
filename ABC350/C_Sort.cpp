#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> nums(N);
    vector<string> ans;
    vector<int> index(N+1);

    
    for (int i = 0; i < N; i ++){
        int num;
        cin >> num;
        nums[i] = num;
        index[num] = i;
    }
    for (int i = 0; i < N; i ++){
        int index_int = index[i + 1];
        if (index_int != i){
            ans.push_back(to_string(nums[index_int]) + " " + to_string(nums[i]));
            swap(nums[index_int], nums[i]);
            swap(index[nums[index_int]], index[nums[i]]);
        } 
    }
    if (ans.size() == 0){
        cout << 0 << endl;
    }
    else{
        cout << ans.size() << endl;
        for (size_t i = 0; i < ans.size(); i++){
            cout << ans[i] << endl;
        }
    }
}