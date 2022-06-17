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
#define mod 1000000007
class Solution {
public:
    int totalSumOfTree=0;
    long long maxProd=0;
    void totalSum(TreeNode* r){
        if(r==NULL){
            return;
        }
        totalSumOfTree+=r->val;
        totalSum(r->left);
        totalSum(r->right);
    }
    long long maxProdCall(TreeNode* r){
        if(r==NULL){
            return 0;
        }
        long long leftSum=maxProdCall(r->left);
        long long rightSum=maxProdCall(r->right);
        long long sumAtThisSubTree=leftSum+rightSum+r->val;
        maxProd=max(maxProd,(sumAtThisSubTree*(totalSumOfTree-sumAtThisSubTree)));
        return sumAtThisSubTree;
    }
    int maxProduct(TreeNode* root){
        totalSum(root);
        maxProdCall(root);
        return maxProd%mod;
    }
};