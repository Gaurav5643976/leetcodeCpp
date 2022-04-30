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
    int ans=0,K;
    void inOrder(TreeNode* r,int &c){
        if(r==NULL){
            return;
        }
        inOrder(r->left,c);
        c++;
        if(c>=K){
            if(c==K){
                ans=r->val;
            }
            return;
        }
        inOrder(r->right,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        K=k;
        inOrder(root,c);
        return ans;
    }
};