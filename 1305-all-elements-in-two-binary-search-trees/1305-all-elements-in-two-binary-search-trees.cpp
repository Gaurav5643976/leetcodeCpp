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
    void inOrder(TreeNode* root,vector<int>& inOrderList){
        if(root==NULL){
            return;
        }
        inOrder(root->left,inOrderList);
        inOrderList.push_back(root->val);
        inOrder(root->right,inOrderList);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> integersOfBST1,integersOfBST2;
        inOrder(root1,integersOfBST1);
        inOrder(root2,integersOfBST2);
        vector<int> combinedIntegerList;
        int n=integersOfBST1.size();
        int m=integersOfBST2.size();
        int start1=0,start2=0;
        while(start1<n and start2<m){
            if(integersOfBST1[start1]<=integersOfBST2[start2]){
                combinedIntegerList.push_back(integersOfBST1[start1]);
                start1++;
            }
            else{
                combinedIntegerList.push_back(integersOfBST2[start2]);
                start2++;
            }
        }
        while(start1<n){
            combinedIntegerList.push_back(integersOfBST1[start1]);
            start1++;
        }
        while(start2<m){
            combinedIntegerList.push_back(integersOfBST2[start2]);
            start2++;
        }
        return combinedIntegerList;
    }
};