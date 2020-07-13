#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 1; i<n; i++) matrix[0][i]+=matrix[0][i-1];
        for(int i = 1; i<m; i++) matrix[i][0]+=matrix[i-1][0];
        
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                matrix[i][j]+=(matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1]);
            }
        }

        for(int i = 0 ; i<m; i++) {
            for(int j = 0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        } 

        int ans = matrix[m-1][n-1];
        /*
        for(int i = 1; i<min(m,n); i++) {
            for(int j = i; j<m; j++) {
                for(int k = i; i<n; k++) {
                    if((matrix[j][k] - 
                        (j-(i+1) >=0 ? matrix[j-(i+1)][k] : 0) - 
                        (k-(i+1)>=0 ? matrix[j][k-(i+1)] : 0) + 
                        (k-(i+1)>=0 && j-(i+1)>=0 ? matrix[j-(i+1)][k-(i+1)] : 0)
                    ) == (i+1)*(i+1)) {
                        ans++;
                      } 
                }
            }
        }
        */

    }
};

int main() {
    vector<vector<int>> matrix;
    Solution s;
    s.countSquares(matrix);
}