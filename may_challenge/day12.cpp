#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    
    int binsearch(vector<int>& arr, int low, int high) {
        if(low<=high) {
            int mid = (low+high)/2;
            if(!((mid>0 && arr[mid-1] == arr[mid]) || (mid<n-1 && arr[mid+1] == arr[mid]))) 
                return arr[mid];
            if(mid&1 && arr[mid] == arr[mid-1])
                return binsearch(arr, mid+1, high);
            if(!(mid&1) && arr[mid] != arr[mid-1])
                return binsearch(arr, mid+1, high);
            return binsearch(arr, low, mid-1);            
        }
        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        n = nums.size();
        return binsearch(nums, 0, n-1);   
    }
};

int main() {
    Solution s;
    vector<int> v1{1,1,2,3,3,4,4,8,8};
    cout<<"ans : "<<s.singleNonDuplicate(v1)<<endl;
}