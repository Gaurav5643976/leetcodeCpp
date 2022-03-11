/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        int noOfNodes=0;
        ListNode* temp=head;
        while(temp){
            noOfNodes++;
            temp=temp->next;
        }
        if(k%noOfNodes==0){
            return head;
        }
        int breakPoint=noOfNodes-k%noOfNodes;
        ListNode *p=NULL,*q=head;
        while(breakPoint--){
            p=q;
            q=q->next;
        }
        p->next=NULL;
        p=q;
        ListNode* ans=q;
        while(q){
            p=q;
            q=q->next;
        }
        p->next=head;
        return ans;
    }
};