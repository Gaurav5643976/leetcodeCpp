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
    int search(int x,vector<int> pos,int st,int end){
        int count=0;
        for(int i=st;i<=end;i++){
            count++;
            if(pos[i]==x){
                return count;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,int stPre,int enPre,int stPos,int enPos){
        if(stPre>enPre or stPos>enPos){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[stPre]);
        if(stPre+1>=preorder.size()){
            return root;
        }
        int len=search(preorder[stPre+1],postorder,stPos,enPos-1);
        if(len==-1){
            return root;
        }
        root->left=solve(preorder,postorder,stPre+1,stPre+len,stPos,stPos+len-1);
        root->right=solve(preorder,postorder,stPre+len+1,enPre,stPos+len,enPos-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
    }
};