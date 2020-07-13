#include <bits/stdc++.h>
using namespace std;


// -----------Jumping index solution.---------------------

// class StockSpanner {
// public:
//     vector<pair<int,int>> vec;
    
//     StockSpanner() {
            
//     }
    
//     int next(int price) {
//         vec.push_back(make_pair(price, 1));
//         for(int i = vec.size()-2; i>=0; i-=vec[i].second) {
//             if(vec[i].first<=price) {
//                 vec[vec.size()-1].second+=vec[i].second;
//             }
//             else break;
//         }
//         return vec[vec.size()-1].second;
//     }
// };


// ---------------solution with stack-----------------
class StockSpanner {
public:
    stack<pair<int,int>> ss;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while(!ss.empty() && ss.top().first<=price) {
            res+=ss.top().second;
            ss.pop();
        }
        ss.push({price, res});
        return res;
    }
};


int main() {
    StockSpanner s;
    cout<<s.next(100)<<" ";
    cout<<s.next(80)<<" ";
    cout<<s.next(60)<<" ";
    cout<<s.next(70)<<" ";
    cout<<s.next(60)<<" ";
    cout<<s.next(75)<<" ";
    cout<<s.next(85)<<" ";
}