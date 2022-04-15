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
        if(head==NULL){
            return head;
        }
        unordered_map<Node*,Node*> um;
        Node* newList=new Node(head->val);
        um[head]=newList;
        Node *temp1=head->next,*temp2=newList;
        while(temp1){
            temp2->next=new Node(temp1->val);
            temp2=temp2->next;
            um[temp1]=temp2;
            temp1=temp1->next;
        }
        temp2=newList,temp1=head;
        while(temp2){
            temp2->random=um[temp1->random];
            temp2=temp2->next;
            temp1=temp1->next;
        }
        return newList;
    }
};