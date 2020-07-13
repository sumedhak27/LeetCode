#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mm;
        for(auto& i : dislikes) {
            mm[i[0]].push_back(i[1]);
            mm[i[1]].push_back(i[0]);
        }
        vector<short> group(N+1, -1);
        int cu_grp = 0;
        for(int i=1; i<=N; i++) {
            if(group[i]!=-1) continue;
            int node = i;
            while(group[node]==-1) {
                group[node] = cu_grp;
                node = mm[node][0];
                cu_grp^=1;
            }
            
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> dislikes{{1,2},{1,3},{1,4},{1,5}};
    cout<<s.possibleBipartition(5, dislikes)<<endl;  
}