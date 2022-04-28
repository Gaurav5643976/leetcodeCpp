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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            unsigned long long v=q.front().second;
            unsigned long long last=0,first=0;
            for(int i=0;i<sz;i++){
                pair<TreeNode*,unsigned long long> p=q.front();
                q.pop();
                if(i==0){
                    first=p.second;
                }
                if(i==sz-1){
                    last=p.second;
                }
                if(p.first->left){
                    q.push({p.first->left,2*(p.second-v)});
                }
                if(p.first->right){
                    q.push({p.first->right,2*(p.second-v)+1});
                }
            }
            int res=last-first+1;
            ans=max(ans,res);
        }
        return ans;
    }
};