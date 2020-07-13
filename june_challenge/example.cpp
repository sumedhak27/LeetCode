#include <bits/stdc++.h>
using namespace std;

class Trie {
    public :
        bool is_last;
        Trie* children[26];
        Trie() : is_last(0) {
            for(int i = 0; i<26; i++) 
                children[i] = nullptr;
        }

        void insert(string word) {
            Trie* cn = this;
            for(auto& c : word) {
                if(cn->children[c-'a'] == nullptr) 
                    cn->children[c-'a'] = new Trie();
                cn = cn->children[c-'a'];
            }
            cn->is_last = 1;
        }

        bool find(string word) {
            Trie* cn = this;
            for(auto& c : word) {
                if(cn->children[c-'a'] != nullptr)
                    cn = cn->children[c-'a'];
                else 
                    return 0;
            }
            return cn->is_last;
        }

};


class Solution {
public:
    int n, m;
    unordered_set<string> ans;
    
    bool recf(int i, int j, vector<vector<char>> board, Trie* cn, string cw) {
        //cout<<board[i][j]-'a'<<endl;
        if(cn->is_last) {
            ans.insert(cw);
            cn->is_last = false;
            return 1;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='0'|| cn->children[board[i][j]-'a'] == nullptr)
            return 0;
        cw+=board[i][j];
        char cchar = board[i][j];
        board[i][j] = '0';
        if(recf(i+1, j, board, cn->children[cchar-'a'], cw)) return 1;
        else if(recf(i, j+1, board, cn->children[cchar-'a'], cw)) return 1;
        else if(recf(i-1, j, board, cn->children[cchar-'a'], cw)) return 1;
        else if(recf(i, j-1, board, cn->children[cchar-'a'], cw)) return 1;
        return 0;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        Trie* root = new Trie();
        for(auto& w : words) 
            root->insert(w);
        for(auto& w : words)
            cout<<root->find(w)<<" ";
        cout<<endl;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                recf(i, j, board, root, "");
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};

int main() {
    Solution s;
    //vector<vector<char>> b {{'a','b'},{'c','d'}};
    //vector<string> w {"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"};
    vector<vector<char>> b {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> w {"oath","pea","eat","rain"};
    vector<string> ans = s.findWords(b, w);
    for(auto& a : ans)
        cout<<a<<" ";
    cout<<endl;
}

//vector<vector<char>> {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
//vector<string> {"oath","pea","eat","rain"};