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
    void inOrder(TreeNode* r,vector<int> &c){
        if(r==NULL){
            return;
        }
        inOrder(r->left,c);
        c.push_back(r->val);
        inOrder(r->right,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> c;
        inOrder(root,c);
        return c[k-1];
    }
};