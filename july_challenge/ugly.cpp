#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long M = 1e5;
    vector<bool> isprime;
    vector<bool> isugly;
    Solution() {
        isprime.resize(M,1);
        for(int i = 2; i<M; i++) {
            if(isprime[i]) {
                for(int j = i*2; j<M; j+=i) {
                    isprime[j] = 0;
                }
            }
        }
        //isugly[2]=0, isugly[3]=0, isugly[5] = 0;
        isugly.resize(M,0);
        for(int i = 7; i<M; i++) {
            if(isprime[i]) {
                for(int j = i; j<M; j+=i) 
                    isugly[j] = 1;
            } 
        }
    }
    int nthUglyNumber(int n) {
        if(n<7) return n;
        int uglycount = 6;
        int i = 7;
        while(n!=uglycount && i<M) 
            if(!isugly[i++]) uglycount++;
        return --i;
    }
};

int main() {
    Solution s;
    s.nthUglyNumber(12);
}