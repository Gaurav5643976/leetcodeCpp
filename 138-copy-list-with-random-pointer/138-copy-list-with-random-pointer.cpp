/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        unordered_map<Node*,Node*> um;
        Node* ans=new Node(head->val);
        Node *temp1=ans,*temp2=head->next;
        um[head]=ans;
        while(temp2){
            temp1->next=new Node(temp2->val);
            um[temp2]=temp1->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1=ans,temp2=head;
        while(temp1){
            temp1->random=um[temp2->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return ans;
    }
};