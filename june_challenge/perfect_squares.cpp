#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int globalmin;
    int recf(int n, vector<int>& ps, int count) {
        if(dp[n]!=-1) 
            return count+dp[n];
        if(n==0) 
            return count;
        if(n<0 || count > globalmin) 
            return INT32_MAX;
        int mincount = INT32_MAX;
        for(int i = ps.size()-1; i>=0; i--) {
            if(ps[i]<=n)
                mincount = min(mincount, recf(n-ps[i], ps, count+1));
        }
        dp[n] = mincount - count;
        globalmin = min(globalmin, mincount);
        return mincount;
    }
    
    int numSquares(int n) {
        dp.resize(n+1, -1);
        globalmin = INT32_MAX;
        vector<int> perfect;
        for(int i = 1; i*i<n; i++) {
            perfect.push_back(i*i);
        }
        return recf(n, perfect, 0);
    }
};

int main() {
    Solution s;
    int num ; cin>>num;
    cout<<s.numSquares(num)<<endl;
}