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
    void solve(TreeNode* r,int& sum){
        if(r==NULL){
            return;
        }
        solve(r->right,sum);
        sum+=r->val;
        r->val=sum;
        solve(r->left,sum);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int s=0;
        solve(root,s);
        return root;
    }
};