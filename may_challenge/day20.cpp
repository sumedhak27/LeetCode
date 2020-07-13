#include <bits/stdc++.h>
using namespace std;

struct TNode {
    int val;
    TNode *left, *right;
    list<int>::iterator listadrr;
    TNode() : val(0), left(nullptr), right(nullptr) {}
    TNode(int num) : val(num), left(nullptr), right(nullptr) {}
};

class BST {
    TNode * root;
    stack<TNode*> ss;
    public :
        BST() : root(nullptr) {}
        void insert(int val) {
            TNode *nn = new TNode(val);
            bool onleft = 1;
            if(!root) root = nn;
            else {
                TNode* parent, *cur_l = root;
                while(cur_l) {
                    if(cur_l->val == val) {
                        cout<<val<<" already exist in the BST."<<endl;
                        return;
                    }
                    else if(cur_l->val>val) {
                        parent = cur_l;
                        cur_l = cur_l->left;
                        onleft = 1;
                    }
                    else {
                        parent = cur_l;
                        cur_l = cur_l->right;
                        onleft = 0;
                    }
                }
                if(onleft) parent->left = nn;
                else parent->right = nn;
            }
        }
        void print() {
            TNode* t = root;
            while(!ss.empty() || t) {
                while(t!=nullptr) {
                    ss.push(t);
                    t=t->left;
                }
                t = ss.top();
                ss.pop();
                cout<<t->val<<" ";
                t=t->right;
            }  
            cout<<endl;         
        }
        void delleaf(TNode* cur_l, TNode* parent, bool onleft) {
            if(onleft) {
                    delete(parent->left);
                    parent->left = nullptr;
                }
                else {
                    delete(parent->right);
                    parent->right = nullptr;
                }
        }
        void delnwsc(TNode* cur_l, TNode* parent, bool onleft) {
            if(!cur_l->left && cur_l->right) {
                if(onleft) 
                    parent->left = cur_l->right;
                else 
                    parent->right = cur_l->right;
            }
            else if(!cur_l->right && cur_l->left) {
                if(onleft) 
                    parent->left = cur_l->left;
                else 
                    parent->right = cur_l->left;
            }
            delete(cur_l);
        }
        void delval(int val) {
            bool onleft = 1;
            TNode* parent, *cur_l = root;
            while(cur_l) {
                if(cur_l->val == val) {
                    break;
                }
                else if(cur_l->val>val) {
                    parent = cur_l;
                    cur_l = cur_l->left;
                    onleft = 1;
                }
                else {
                    parent = cur_l;
                    cur_l = cur_l->right;
                    onleft = 0;
                }
            }
            if(!cur_l->left && !cur_l->right) {
                delleaf(cur_l, parent, onleft);
            }
            else if(!cur_l->left || !cur_l->right) {
                delnwsc(cur_l, parent, onleft);
            }
            else {
                TNode* t = cur_l->right, *t_parent = cur_l;
                while(t->left) {
                    t_parent = t;
                    t=t->left;
                } 
                if(!t->right) {
                    delleaf(t, t_parent, true);
                }
                else {
                    delnwsc(cur_l, parent, true);
                }
            }
            
        }
};

int main() {
    BST bt;
    bt.insert(27);
    for(int i = 0; i<10; i++) bt.insert(rand()%100);
    bt.print();
}