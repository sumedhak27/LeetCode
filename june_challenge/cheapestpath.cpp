#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,vector< pair<int,int>>> vicecity;
    vector<long long> dp;
    
    long long recpath(int cst, int dst, int k, int cost) {
        if(dp[cst]!=-1) return cost+dp[cst];
        if(k<0) return INT32_MAX;
        if(cst == dst) return cost;
        long long ans = INT32_MAX;
        for(auto& itr : vicecity[cst]) {
            ans = min(recpath(itr.first,  dst, k-1, cost+itr.second), ans);
        }
        if(ans!=INT32_MAX)
            dp[cst] = ans-cost;
        return ans;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        dp.resize(n, -1);
        for(auto& i : flights) 
            vicecity[i[0]].push_back({i[1],i[2]});
        int ans = recpath(src, dst, K+1, 0);
        return ans==INT32_MAX ? -1 : ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    cout<<"ans : "<<s.findCheapestPrice(5, vec, 0, 2, 2)<<endl;
}