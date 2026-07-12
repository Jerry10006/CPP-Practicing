#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<pair<int, int>> projects; //need, earn
        for (int i = 0; i < profits.size(); i++){
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>> remaining;

        int project = 0, quota = 0;

        while (quota < min(k, static_cast<int>(projects.size()))){
            if (w < projects[project].first && remaining.empty()) break;

            while (project < projects.size() && projects[project].first <= w){
                remaining.push({projects[project].second, projects[project].first});
                project++;
            }

            w += remaining.top().first;
            remaining.pop();
            quota++;
        }   

        return w;
    }
};