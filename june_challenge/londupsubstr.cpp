#include <bits/stdc++.h>
using namespace std;
long long M = (long long)1e15+7;

class Solution {
public:
    string subs;
    

    bool substr2(int len, string s) {
        if(len==0) return true;
        for(int i = 0; i<s.length()-len; i++) {
            string pattern = s.substr(i, len);
            long long hash = 0;
            /*
            for(int k = i; k<i+len; k++) {
                hash = (26*hash)+(s[k]-'a'+1"banana");
            }
            */
            for(int k = i; k<i+len; k++) {
                hash+=(s[k]-'a'+1);
            }
            long long hash2 = hash;
            //long long power = pow(26,len-1);
            for(int j = i+1; j<=s.length()-len; j++) {
                //hash2-=power*(s[j-1]-'a'+1);
                //hash2*=26;
                //hash2+=(s[j+len-1]-'a'+1);
                hash2-=(s[j]-'a'+1);
                hash2+=(s[j+len-1]-'a'+1);
                if(hash==hash2 && pattern==s.substr(j,len)) {
                    subs = pattern;
                    return true;
                }
            }
        }
    }
    
    bool substr(int len, string s) {
        if(len == 0) return true;
        for(int i = 0; i<=s.length()-len-1; i++) {
            string pattern = s.substr(i, len);
            for(int j = i+1; j<=s.length()-len; j++) {
                if(pattern == s.substr(j, len)) {
                    subs = pattern;
                    return true;
                }
            }
        }
        return false;
    }
    
    string longestDupSubstring(string S) {
        subs = "";
        int l = 0, h = S.length()-1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(substr3(mid, S)) l = mid+1;
            else h = mid-1;
        }
        return subs;
    }
};

int main() {
    Solution s;
    string in; cin>>in;
    cout<<s.longestDupSubstring(in)<<endl;
}
