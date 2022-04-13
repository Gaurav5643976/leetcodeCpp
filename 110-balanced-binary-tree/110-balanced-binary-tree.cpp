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
    bool st=true;
    int height(TreeNode* r){
        if(!r){
            return 0;
        }
        int lh=height(r->left);
        int rh=height(r->right);
        st =st and abs(lh-rh)<=1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return st;
    }
};