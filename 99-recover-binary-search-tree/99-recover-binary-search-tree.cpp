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
    
    TreeNode *first=NULL,*second=NULL;
    TreeNode* prev=new TreeNode(INT_MIN);
    void solve(TreeNode* r){
        if(!r){
            return;
        }
        solve(r->left);
        if(first==NULL and prev->val>r->val){
            first=prev;
        }
        if(first!=NULL and prev->val>r->val){
            second=r;
        }
        prev=r;
        solve(r->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        //cout<<first<<" "<<second;
        swap(first->val,second->val);
    }
};