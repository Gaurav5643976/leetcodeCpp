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
    void solve(TreeNode* r,int& count,int ma){
        if(r==NULL){
            return;
        }
        ma=max(ma,r->val);
        if(r->val>=ma){
            count++;
        }
        solve(r->left,count,ma);
        solve(r->right,count,ma);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count=0,ma=INT_MIN;
        solve(root,count,ma);
        return count;
    }
};