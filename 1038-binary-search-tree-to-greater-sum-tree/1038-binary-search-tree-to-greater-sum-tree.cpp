/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* r,int& s){
        if(r==NULL){
            return;
        }
        solve(r->right,s);
        s+=r->val;
        r->val=s;
        solve(r->left,s);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int s=0;
        solve(root,s);
        return root;
    }
};