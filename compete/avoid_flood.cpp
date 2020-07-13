#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> recf(
        vector<int>& rains, 
        int i, 
        vector<int> ans,
        unordered_set<int> s, 
        vector<int> vec
    ) {
        if(i==rains.size())
            return ans;
        if(rains[i]) {
            if(s.find(rains[i])!=s.end())
                return vector<int>();
            ans.push_back(-1);
            s.insert(rains[i]);
            vec.push_back(rains[i]);
            return recf(rains, i+1, ans, s, vec);
        }
        else {
            for(int j = 0; j<vec.size(); j++) {
                int t = vec[j];
                ans.push_back(t);
                s.erase(t);
                vec.erase(vec.begin()+j);
                vector<int> tvec = recf(rains, i+1, ans, s, vec);
                if(tvec.size() == rains.size()) return tvec;
                vec.insert(vec.begin()+j,t);
                s.insert(t);
                ans.pop_back();
            }
        }
        return vector<int>();
    }
    
    vector<int> avoidFlood(vector<int>& rains) {
        return recf(rains, 0, vector<int>(), unordered_set<int>(), vector<int>());        
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,3,4};
    vector<int> ans = s.avoidFlood(v);
    for(auto& i : ans)
        cout<<i<<" ";
    cout<<endl;
}