Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.


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
    map<int,vector<int>> m;
    void level(TreeNode* rt,int c){
        if(!rt){
            return;
        }
        m[c].push_back(rt->val);
        level(rt->left,c+1);
        level(rt->right,c+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int l=0;
        vector<double> ans;
        level(root,0);
        for(auto i:m){
            long double s=0;
            vector<int> vec=i.second;
            for(auto j:vec){
                s+=j;
            }
            int n=vec.size();
            double d=s/n;
            ans.push_back(d);
        }
        return ans;
    }
};