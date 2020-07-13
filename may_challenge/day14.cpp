#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i<n; i++) {
            arr.push_back(arr[i]);
        }
        cout<<arr.size()<<endl;
        int cur_max = arr[0], global_max = arr[0], sp = 0;
        for(int i = 1; i<arr.size() && i-sp<n; i++) {
            if(arr[i] > cur_max + arr[i]){
                cur_max = arr[i];
                sp = i;
            }
            else 
                cur_max+=arr[i];
            
            global_max = max(global_max,cur_max);
        }
        return global_max;
    }
};

int main() {
    Solution s;
    vector<int> vec{5,-3,5};
    s.maxSubarraySumCircular(vec);
}