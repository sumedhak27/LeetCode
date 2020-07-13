#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        vector<int> mm(256,0);
        for(char c: s) 
            mm[int(c)]++;
        vector<pair<char, int>> vec;
        for(int i = 0; i<mm.size(); i++)
            if(mm[i]>0)
                vec.push_back({ char(i), mm[i]});
        sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b) { return a.second>b.second;});
        for(auto p : vec)
            for(int i = 0; i<p.second; i++) 
                ans+=p.first;
        return ans;
    }
};

int main() {
    string str = "bbaA";
    Solution s;
    cout<<s.frequencySort(str)<<endl;
}