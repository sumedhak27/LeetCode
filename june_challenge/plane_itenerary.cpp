#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string, set<string>>& mp, vector<string>& ans) {
        if(mp.empty()) 
            return;
        string cs = ans.back();
        string ns = *(mp[cs].begin());
        ans.push_back(ns);
        mp[cs].erase(ns);
        dfs(mp, ans);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, set<string>> mp;
        vector<string> ans;
        for(auto& t: tickets) {
            mp[t[0]].insert(t[1]);
        }
        if(mp.find("JFK")==mp.end()) 
            return ans;
        ans.push_back("JFK");
        dfs(mp, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> tickets {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
}