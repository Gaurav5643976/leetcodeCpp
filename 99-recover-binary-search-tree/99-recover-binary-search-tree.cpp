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
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode *first=NULL, *second=NULL;
    void inorderTraversal(TreeNode* r){
        if(!r){
            return;
        }
        inorderTraversal(r->left);
        if(first==NULL and prev->val>r->val){
            first=prev;
            //second=r;
        }
        if(first!=NULL and prev->val>r->val){
            second=r;
        }
        prev=r;
        inorderTraversal(r->right);
    }
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        //cout<<first->val<<" "<<second->val;
        swap(first->val,second->val);
    }
};