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
    void solve(TreeNode* r,int& count,int v){
        if(!r){
            return;
        }
        int ma=max(v,r->val);
        if(ma==r->val){
            count++;
        }
        solve(r->left,count,ma);
        solve(r->right,count,ma);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        solve(root,count,INT_MIN);
        return count;
    }
};