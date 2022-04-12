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
    vector<TreeNode*> ans;
    void postOrder(TreeNode*& r,unordered_set<int>& st){
        if(r==NULL){
            return;
        }
        postOrder(r->left,st);
        postOrder(r->right,st);
        if(st.find(r->val)!=st.end()){
            if(r->left){
                ans.push_back(r->left);
            }
            if(r->right){
                ans.push_back(r->right);
            }
            r=NULL;
            delete(r);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        postOrder(root,st);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};