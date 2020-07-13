#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    struct Node{
        TreeNode* tn;
        int ind;
    };
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        queue<Node> kyu;
        kyu.push({root, 0});
        while(!kyu.empty()) {
            Node cn = kyu.front();
            kyu.pop();
            cout<<ans.size()<<" "<<cn.ind<<","<<cn.tn->val<<"\t";
            if(ans.size() <= cn.ind)
                ans.push_back(vector<int>());
            ans[cn.ind].push_back((cn.tn->val));
            if(cn.tn->left) kyu.push({cn.tn->left, cn.ind+1});
            if(cn.tn->right) kyu.push({cn.tn->right, cn.ind+1});
        }
        return vector<vector<int>>(ans.rbegin(), ans.rend());
    }
};

int main() {
    Solution s;
    TreeNode tn1(15);
    TreeNode tn2(7);
    TreeNode tn3(20, &tn1, &tn2);
    TreeNode tn4(9);
    TreeNode root(3, &tn3, &tn4);
    s.levelOrderBottom(&root);
}