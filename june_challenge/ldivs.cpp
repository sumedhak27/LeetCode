#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //set<pair<int, int>> depths;
    //unordered_map<int,pair<int,int>> depths;
    vector<pair<int,int>> dp;
    vector<int> num;
    int getdepth(int ind) {
        if(dp[ind].first!=-1) return dp[ind].first;
        //if(depths.find(ind)!=depths.end()) return depths[ind].first;
        //depths[ind] = {0,-1};
        dp[ind].first = 0;
        for(int i = ind-1; i>=0; i--) {
            if(!(num[ind]%num[i])) {
                //depth = max(depth, getdepth(i)+1);
                int nd = getdepth(i)+1;
                /*
                if(nd > depths[ind].first) {
                    depths[ind].second = i;
                    depths[ind].first= nd;
                }
                */
                if(nd > dp[ind].first) {
                    dp[ind].second = i;
                    dp[ind].first = nd;
                }
            }
        }
        //if(!(depths[ind].first)) depths[ind].first = 1;
        //return depths[ind].first;
        if(!(dp[ind].first)) dp[ind].first = 1;
        return dp[ind].first;
    }

    vector<int> largestDivisibleSubsett(const vector<int>& nums) {
        num = nums;
        sort(num.begin(), num.end());
        int n = num.size();
        if(n==0 || n==1) return num;
        dp.resize(n,{-1,-1});
        int maxdepth = 0;
        int maxind = 0;
        for(int i = n-1; i>=0; i--) {
            //maxdepth = max(maxdepth, getdepth(i)); 
            int nmd = getdepth(i);
            if(nmd>maxdepth) {
                maxdepth = nmd;
                maxind = i;
            }
        }
        //for(auto& itr : depths) cout<<itr.first<<" : "<<itr.second.first<<","<<itr.second.second<<endl;
        //cout<<maxdepth<<endl;
        /*
        vector<int> ans;
        while(maxind!=-1) {
            ans.push_back(num[maxind]);
            //maxind = depths[maxind].second;
            maxind = dp[maxind].second;
        }
        reverse(ans.begin(), ans.end());
        */
        vector<int> ans(maxdepth);
        int k = maxdepth-1;
        while(maxind!=-1) {
            ans[k--] = num[maxind];
            maxind = dp[maxind].second;
        } 

        for(auto& i : ans) cout<<i<<" ";
        cout<<endl;
        return ans;
    }


    vector<int> largestDivisibleSubset(vector<int>& num) {
        sort(num.begin(), num.end());
        int n = num.size();
        int maxind = 0, maxval = 0;
        vector<int> dp(n, 0);
        vector<int> parent(n,-1);
        for(int i = 0; i<n; i++) {
            for(int j = i-1; j>=0; j--) {
                if(!(num[i]%num[j])) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                    } 
                }
            }        
            if(!dp[i]) dp[i]=1;
            if(dp[i]>maxval) {
                maxval = dp[i];
                maxind = i;
            }
        }
        vector<int> ans(maxval);
        int k = maxval-1;
        while(maxind!=-1){
            ans[k--] = num[maxind];
            maxind = parent[maxind];
        }
        for(auto& i : ans) cout<<i<<" ";
        cout<<endl;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> vec {4,8,10,240};
    s.largestDivisibleSubset(vec);
}