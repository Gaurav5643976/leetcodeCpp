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
    void inorder(TreeNode* r,vector<int>& v){
        if(r==NULL){
            return;
        }
        inorder(r->left,v);
        v.push_back(r->val);
        inorder(r->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> element;
        inorder(root,element);
        int i=0,j=element.size()-1;
        while(i<j){
            if(element[i]+element[j]==k){
                return true;
            }
            else if(element[i]+element[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};