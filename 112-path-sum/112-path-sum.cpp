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
    bool flag=false;
    void solve(TreeNode* r,int required){
        if(r==NULL){
            return;
        }
        required-=r->val;
        if(r->left==NULL and r->right==NULL and required==0){
            flag=true;
            return;
        }
        solve(r->left,required);
        solve(r->right,required);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return flag;
    }
};