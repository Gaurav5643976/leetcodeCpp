/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    pair<string,int> find(string str,int i){
        string value="";
        while(str[i]!=','){
            value+=str[i];
            i++;
        }
        return {value,i+1};
    }
    string serialize(TreeNode* root) {
        string str="";
        if(root==NULL){
            return str;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node){
                str+=to_string(node->val)+',';
                q.push(node->left);
                q.push(node->right);
            }
            else{
                str+="n,";
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==""){
            return NULL;
        }
        pair<string,int> p=find(data,0);
        TreeNode* root=new TreeNode(stoi(p.first));
        queue<TreeNode*> q;
        q.push(root);
        //int k=3;
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            p=find(data,p.second);
            if(p.first=="n"){
                node->left=NULL;
            }
            else{
                TreeNode* leftNode=new TreeNode(stoi(p.first));
                node->left=leftNode;
                q.push(leftNode);
            }
            if(p.second>=data.size()){
                break;
            }
            p=find(data,p.second);
            if(p.first=="n"){
                node->right=NULL;
            }
            else{
                TreeNode* rightNode=new TreeNode(stoi(p.first));
                node->right=rightNode;
                q.push(rightNode);
            }
            if(p.second>=data.size()){
                break;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));