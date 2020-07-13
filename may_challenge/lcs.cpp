#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int n, m;
    vector<vector<int>> mem;
    
    int recf(int i, int j, int count, vector<int>& A, vector<int>& B) {
        if(i==n || j==m) 
            return count;
        int ret = 0;
        if(mem[i][j]!=-1) 
            ret = mem[i][j];
        else if(A[i] == B[j]) 
            ret = recf(i+1, j+1, count+1, A, B);
        else 
            ret = max(recf(i, j+1, count, A, B), recf(i+1, j, count, A, B));
        mem[i][j] = ret;
        return ret;
    }
    
    int recf2(int i, int j, int count, vector<int>& A, vector<int>& B) {
        if(i == -1 || j == -1)
            return count;
        int ret = 0;
        if(mem[i][j] != -1) 
            ret = mem[i][j];
        else if(A[i] == B[j])
            ret = recf2(i-1, j-1, count+1, A, B);
        else
            ret = max(recf2(i, j-1, count, A, B), recf2(i-1, j, count, A, B));
        mem[i][j] = ret;
        return mem[i][j];
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        n = A.size(), m = B.size();
        mem.resize(n, vector<int>(m, -1));
        int ret = recf(0, 0, 0, A, B);
        //int ret = recf2(n-1, m-1, 0, A, B);
        for(int i = 0; i<n ;i++) {
            for(int j = 0; j<m; j++)
                cout<<mem[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl<<endl;
        //return ret;
        
        
        mem.clear();
        mem.resize(n+1, vector<int>(m+1));
        for(int i = 0; i<=n; i++) {
            for(int j = 0; j<=m; j++) {
                if(i == 0 || j == 0) 
                    mem[i][j] = 0;
                else if(A[i-1] == B[j-1])
                    mem[i][j] = mem[i-1][j-1] + 1;
                else
                    mem[i][j] = max(mem[i][j-1], mem[i-1][j]);
            }
        }
        for(int i = 1; i<=n ;i++) {
            for(int j = 1; j<=m; j++)
                cout<<mem[i][j]<<"\t";
            cout<<endl;
        }
        return ret;
        
    }
};

int main() {
    Solution s;
    vector<int> A {2,3,1};
    vector<int> B {3,1,3,3,3,3};
    cout<<"ans :  "<<s.maxUncrossedLines(A, B)<<endl;
}