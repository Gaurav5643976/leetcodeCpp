/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            while(n--){
                Node* temp=q.front();
                q.pop();
                if(temp){
                    v.push_back(temp->val);
                    for(Node* i:temp->children){
                        q.push(i);
                    }
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};