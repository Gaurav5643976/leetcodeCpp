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
    void solve(TreeNode* r,int& mi,int& last){
        if(r==NULL){
            return;
        }
        solve(r->left,mi,last);
        if(last!=-1){
            mi=min(mi,abs(last-r->val));
        }
        last=r->val;
        solve(r->right,mi,last);
    }
    int getMinimumDifference(TreeNode* root) {
        int minAbsDiff=INT_MAX;
        int l=-1;
        solve(root,minAbsDiff,l);
        return minAbsDiff;
    }
};