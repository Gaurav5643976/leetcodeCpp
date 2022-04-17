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
    vector<int> v;
    void solve(TreeNode* r){
        if(r==NULL){
            return;
        }
        solve(r->left);
        v.push_back(r->val);
        solve(r->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        solve(root);
        TreeNode* head=new TreeNode(v[0]);
        TreeNode* temp=head;
        for(int i=1;i<v.size();i++){
            temp->right=new TreeNode(v[i]);
            temp=temp->right;
        }
        return head;
    }
};