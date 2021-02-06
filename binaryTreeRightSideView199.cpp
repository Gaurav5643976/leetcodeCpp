// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---


class Solution {
public:
    void rightView(TreeNode* root, int level,int &m,vector<int>& res){
        if(!root){
            return;
        }
        if(m<level){
            res.push_back(root->val);
            m=level;
        }
        rightView(root->right,level+1,m,res);
        rightView(root->left,level+1,m,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        int maxLevel=0;
        vector<int> ans;
        rightView(root,1,maxLevel,ans);
        return ans;
    }
};