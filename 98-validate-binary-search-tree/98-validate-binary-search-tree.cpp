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
    void solve(TreeNode* r,TreeNode*& last,bool& isValid){
        if(r==NULL){
            return;
        }
        solve(r->left,last,isValid);
        if(last and last->val>=r->val){
            cout<<last->val<<" "<<r->val;
            isValid=false;
        }
        last=r;
        solve(r->right,last,isValid);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* last=NULL;
        bool isValid=true;
        solve(root,last,isValid);
        return isValid;
    }
};