#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        multimap<int, int, greater<int>> mm;
        vector<int> vec;
        if(k>=num.length()) return 0;
        int ck = 0;
        for(int i = 0; i<num.length() || vec.size()<k; i++) {
            if(vec.size()>=k) break;
            if(ck == k || i == num.length()-1) {
                pair<int, int> maxp = *mm.begin();
                mm.erase(mm.begin());
                vec.push_back(maxp.second);
                ck--; 
            }
            mm.insert(make_pair(num[i], i));
            ck++;
        }
        for(int i = 0; i<vec.size(); i++) {
            num.erase(num.begin()+vec[i]-i);
        }

        return num;
    }
};

int main() {
    Solution s;
    cout<<s.removeKdigits("1432219",3)<<endl;
}