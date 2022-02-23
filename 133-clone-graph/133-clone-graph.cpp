/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* r,unordered_map<int,Node*>& um){
        if(um.find(r->val)!=um.end()){
            return um[r->val];
        }
        Node* n=new Node(r->val);
        um[r->val]=n;
        for(Node* nbr:r->neighbors){
            n->neighbors.push_back(clone(nbr,um));
        }
        return n;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<int,Node*> um;
        return clone(node,um);
    }
};