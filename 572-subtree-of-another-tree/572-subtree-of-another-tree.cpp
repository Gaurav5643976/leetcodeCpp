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
    vector<TreeNode*> r;
    void traverse(TreeNode* r1,TreeNode* r2){
        if(r1==NULL){
            return;
        }
        if(r1->val==r2->val){
            r.push_back(r1);
        }
        traverse(r1->left,r2);
        traverse(r1->right,r2);
    }
    bool isSame(TreeNode* r1,TreeNode* r2){
        if(r1==NULL and r2==NULL){
            return true;
        }
        if(r1 and r2 and r1->val==r2->val and isSame(r1->left,r2->left) and isSame(r1->right,r2->right)){
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        traverse(root,subRoot);
        for(auto i:r){
            if(isSame(i,subRoot)){
                return true;
            }
        }
        return false;
    }
};