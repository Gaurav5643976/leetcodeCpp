// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    Node* ro=NULL;
    unordered_set<Node*> st;
    void dfs(Node* r,unordered_map<Node*,Node*>& um,Node* parent,int target){
        if(r==NULL){
            return;
        }
        if(r->data==target){
            ro=r;
        }
        //cout<<r->data<<" ";
        um[r]=parent;
        dfs(r->left,um,r,target);
        dfs(r->right,um,r,target);
    }
    void solve(int& sum,Node* r,unordered_map<Node*,Node*>& um,int k){
        if(r==NULL or k<0 or st.find(r)!=st.end()){
            return;
        }
        st.insert(r);
        sum+=r->data;
        solve(sum,r->left,um,k-1);
        solve(sum,r->right,um,k-1);
        solve(sum,um[r],um,k-1);
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        // code here
        unordered_map<Node*,Node*> um;
        dfs(root,um,NULL,target);
        int sum=0;
        //cout<<ro->data<<" ";
        solve(sum,ro,um,k);
        return sum;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends