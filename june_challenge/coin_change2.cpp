#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recf(vector<int>& coins, int amount, int ind, int camount) {
        if(camount>amount) return 0;
        if(camount==amount) return 1;
        if(ind >= coins.size()) return 0;
        return recf(coins, amount, ind, camount+coins[ind]) +
                recf(coins, amount, ind+1, camount+coins[ind]) +
                recf(coins, amount, ind+1, camount);
    }
    
    int change(int amount,vector<int>& coins) {
        return recf(coins, amount, 0, 0);
    }
};

int main() {
    Solution s;
    vector<int> v1 {1,2,5};
    s.change(5, v1);
}