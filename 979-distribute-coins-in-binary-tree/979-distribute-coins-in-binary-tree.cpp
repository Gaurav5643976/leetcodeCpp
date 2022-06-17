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
    int minMoves=0;
    int postOrderCall(TreeNode* r){
        if(r==NULL){
            return 0;
        }
        int leftRequirement=postOrderCall(r->left);
        int rightRequirement=postOrderCall(r->right);
        minMoves+=abs(leftRequirement)+abs(rightRequirement);
        return leftRequirement+rightRequirement+(r->val-1);
    }
    int distributeCoins(TreeNode* root) {
        postOrderCall(root);
        return minMoves;
    }
};