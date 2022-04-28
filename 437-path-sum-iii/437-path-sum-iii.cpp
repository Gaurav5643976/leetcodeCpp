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
    int ans=0;
    void solve(TreeNode* r,int t,long long sum,unordered_map<int,int> um){
        if(r==NULL){
            return;
        }
        sum+=r->val;
        if(um.find(sum-t)!=um.end()){
            ans+=um[sum-t];
        }
        um[sum]++;
        solve(r->left,t,sum,um);
        solve(r->right,t,sum,um);
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> um;
        um[0]=1;
        solve(root,targetSum,0,um);
        return ans;
    }
};