#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string get_next_permutation(string s) {
        set<char> se;
        se.insert(s.back());
        s.pop_back();
        while(s.length()) {
            se.insert(s.back());
            auto itr = se.upper_bound(s.back());
            s.pop_back();
            if(itr!=se.end()) {
                s.push_back(*itr);
                se.erase(itr);
                for(auto& i : se) {
                    s.push_back(i);
                }
                break;
            } 
        }
        return s;
    }
    
    int bin_search(string& s, int l, int r, int key) {
        int big_i = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(s[mid]<=key) 
                r = mid-1;
            else {
                l = mid+1;
                if(big_i==-1 || s[big_i]>=s[mid])
                    big_i = mid;
            }
        }
        return big_i;
    }
    
    bool get_next_per(string& s) {
        int i = s.length()-1;
        while(i && s[i-1]>=s[i]) 
            i--;
        if(i<0) 
            return 0;
        int next_big = bin_search(s, i, s.length()-1, s[i-1]);
        swap(s[i-1], s[next_big]);
        reverse(s.begin()+i, s.end());
        return 1;
    }
    
    string getPermutation(int n, int k) {
        /*
        vector<int> per(n);
        vector<char> arr(n);
        for(int i = 0; i<n; i++) {
            arr[i] = i+1 + '0';
            per[i] = i ? per[i-1]*(i+1) : 1;
        }
        int ind = 0;
        int gsize = n-2;
        string ans = "";
        for(int i = 1; i<n; i++) {
            ind = k/per[gsize];
            if(!(k%per[gsize])) 
                ind--, k = per[gsize];
            else 
                k%=per[gsize]);
            ans.push_back(arr[ind]);
            arr.erase(arr.begin()+ind);
            gsize--;
        }
        ans.push_back(arr[0]);
        */
        
        
        string ans;
        for(int i = 1; i<=n; i++)
            ans.push_back(i+'0');
        /*
        for(int i = 1; i<k; i++) {
            ans=get_next_permutation(ans);
        }
        */
        
        while(--k) {
            if(get_next_per(ans));
            else break;
        }
        
        
        return ans;
    }
    
};

int main() {
    Solution s;
    int n, k; cin>>n>>k;
    /*
    for(int k = 1; k<=120; k++) {
        cout<<s.getPermutation(5,k)<<endl;
    }
    */
    cout<<s.getPermutation(n,k)<<endl;
}