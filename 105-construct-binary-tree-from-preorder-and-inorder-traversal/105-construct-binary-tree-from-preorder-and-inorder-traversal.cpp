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
    TreeNode* solve(vector<int> pre,vector<int> in,int pStart,int pEnd,int iStart,int iEnd){
        if(pStart>pEnd or iStart>iEnd){
            return NULL;
        }
        int indx;
        for(int i=iStart;i<=iEnd;i++){
            if(in[i]==pre[pStart]){
                indx=i;
                break;
            }
        }
        int lenOfLeftSubTree=indx-iStart,lenOfRightSubTree=iEnd-indx;
        TreeNode* r=new TreeNode(pre[pStart]);
        r->left=solve(pre,in,pStart+1,pStart+lenOfLeftSubTree,iStart,indx-1);
        r->right=solve(pre,in,pStart+lenOfLeftSubTree+1,pEnd,indx+1,iEnd);
        return r;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return solve(preorder,inorder,0,n-1,0,n-1);
    }
};