/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int K;
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_set<TreeNode*> st;
    void storeParent(TreeNode* r,TreeNode* p){
        if(r==NULL){
            return;
        }
        par[r]=p;
        storeParent(r->left,r);
        storeParent(r->right,r);
    }
    void traverse(TreeNode* r,TreeNode* t){
        if(r==NULL){
            return;
        }
        if(r->val==t->val){
            solve(r,K);
        }
        traverse(r->left,t);
        traverse(r->right,t);
    }
    void solve(TreeNode* r,int k){
        if(r==NULL or st.find(r)!=st.end()){
            return;
        }
        st.insert(r);
        if(k==0){
            ans.push_back(r->val);
        }
        solve(r->left,k-1);
        solve(r->right,k-1);
        solve(par[r],k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        K=k;
        storeParent(root,NULL);
        traverse(root,target);
        return ans;
    }
};