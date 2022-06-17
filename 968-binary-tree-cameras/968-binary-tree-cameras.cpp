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
    int cameraCount=0;
    int needsCamera=0;
    int hasCamera=1;
    int covered=2;
    int notNeeded=3;
public:
    int getcameraStatusForEachNode(TreeNode* r){
        if(r==NULL){
            return notNeeded;
        }
        // leaf node
        if(r->left==NULL and r->right==NULL){
            return needsCamera;
        }
        int leftStatus=getcameraStatusForEachNode(r->left);
        int rightStatus=getcameraStatusForEachNode(r->right);
        if(leftStatus==needsCamera or rightStatus==needsCamera){
            cameraCount++;
            return hasCamera;
        }
        if(leftStatus==hasCamera or rightStatus==hasCamera){
            return covered;
        }
        return needsCamera;
    }
    int minCameraCover(TreeNode* root) {
        cameraCount=getcameraStatusForEachNode(root)==needsCamera?cameraCount+1:cameraCount;
        return cameraCount;
    }
};