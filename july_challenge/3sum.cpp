#include <bits/stdc++.h>
using namespace std;
class Solution {
public : 
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        map<int, int> mp;
        for(int i : nums) mp[i]++;
        
        for(auto i = mp.begin(); next(i)!=--mp.end(); i++) {
            i->second--;
            for(auto j = next(i); j!=--mp.end(); j++) {
                j->second--;
                int z = -(i->first+j->first);
                if(mp.find(z)!=mp.end() && mp[z]) {
                    if(i->first<=j->first && i->first<=z)
                        ans.insert({i->first, min(j->first, z), max(j->first, z)});
                    else if(j->first<=i->first && j->first<=z)
                        ans.insert({j->first, min(i->first, z), max(i->first, z)});
                    else
                        ans.insert({z, min(j->first, i->first), max(j->first, i->first)});
                }
                j->second++;
            }
            i->second++;
        }
        if(mp[0]>2) ans.insert({0,0,0});
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main() {
    Solution s;
    vector<int> v {-1,0,1,2,-1,-4};
    s.threeSum(v);

}