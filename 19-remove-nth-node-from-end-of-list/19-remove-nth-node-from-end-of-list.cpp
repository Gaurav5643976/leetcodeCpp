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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int noOfNodes=0;
        while(temp){
            noOfNodes++;
            temp=temp->next;
        }
        int fromStart=noOfNodes+1-n;
        if(fromStart==1){
            return head->next;
        }
        temp=head;
        ListNode* t=NULL;
        while(--fromStart){
            t=temp;
            temp=temp->next;
        }
        t->next=temp->next;
        delete(temp);
        return head;
    }
};