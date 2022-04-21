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
    unordered_set<string> st;
    void solve(TreeNode* r,vector<string>& ans,vector<int> v){
        if(r==NULL){
            return;
        }
        v.push_back(r->val);
        if(r->left==NULL and r->right==NULL){
            string str="";
            for(auto i:v){
                str+=(to_string(i)+"->");
            }
            str.pop_back();
            str.pop_back();
            if(st.find(str)==st.end()){
                ans.push_back(str);
                st.insert(str);
            }
            return;
        }
        solve(r->left,ans,v);
        solve(r->right,ans,v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> v;
        solve(root,ans,v);
        return ans;
    }
};