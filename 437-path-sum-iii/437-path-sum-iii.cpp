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
    int ans=0;
    void helper(TreeNode* root, long long target){
        if(root==NULL){
            return;
        }
        if(root->val==target){
            ans++;
        }
        target-=root->val;
        helper(root->left,target);
        helper(root->right,target);
    }
    int pathSum(TreeNode* root, int target) {
        if(root==NULL){
            return 0;
        }
        helper(root,target);
        pathSum(root->left,target);
        pathSum(root->right,target);
        return ans;
    }
};