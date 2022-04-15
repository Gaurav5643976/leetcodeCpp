/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void flattenUtil(Node* temp,Node* nxt,Node* child){
        temp->next=child;
        child->prev=temp;
        temp->child=NULL;
        Node* temp1=child;
        Node* pre=NULL;
        while(temp1){
            pre=temp1;
            if(temp1->child){
                flattenUtil(temp1,temp1->next,temp1->child);
            }
            temp1=temp1->next;
        }
        pre->next=nxt;
        if(nxt){
            nxt->prev=pre;
        }
    }
    Node* flatten(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        while(temp){
            if(temp->child){
                flattenUtil(temp,temp->next,temp->child);
            }
            temp=temp->next;
        }
        return head;
    }
};