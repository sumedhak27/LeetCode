#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree() {
        vector<bool> vec {1,1,1,1,0,0,1,1,0,0,0,0,0,0,1};
        int n = vec.size()-1;
        int nod = 1, x = 1, l = 0, r = 0, maxwidth = 0;
        for(int i = 1; i<=n; i++) {
            if(i==nod) {
                //cout<<x<<" ";
                maxwidth = max(maxwidth, r-l+1);
                l = r = -1;
                nod+=(x<<=1);
            }
            if(vec[i]) {
                if(l==-1) l = r = i;
                else r = i;
            }
        }
        maxwidth = max(maxwidth, r-l+1);
        return maxwidth;
    }
};


int main() {
    Solution s;
    s.widthOfBinaryTree();
}