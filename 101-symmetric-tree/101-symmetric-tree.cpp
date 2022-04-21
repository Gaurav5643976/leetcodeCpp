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
    bool solve(TreeNode* r1,TreeNode* r2){
        if(r1==NULL and r2==NULL){
            return true;
        }
        if(r1 and r2 and r1->val==r2->val and solve(r1->left,r2->right) and solve(r1->right,r2->left)){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }
};