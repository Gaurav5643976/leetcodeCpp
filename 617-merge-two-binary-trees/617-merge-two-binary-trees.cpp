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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2){
            return NULL;
        }
        TreeNode* root=new TreeNode(0);
        root->val=(root1?root1->val:0) + (root2?root2->val:0);
        TreeNode *l1=root1?root1->left:NULL;
        TreeNode *l2=root2?root2->left:NULL;
        TreeNode *r1=root1?root1->right:NULL;
        TreeNode *r2=root2?root2->right:NULL;
        root->left=mergeTrees(l1,l2);
        root->right=mergeTrees(r1,r2);
        return root;
    }
};