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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *pre=NULL,*cur=dummy;
        for(int i=0;i<left;i++){
            pre=cur;
            cur=cur->next;
        }
        ListNode *prev=pre,*curr=cur,*nxt=NULL;
        for(int i=left;i<=right;i++){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        pre->next=prev;
        cur->next=curr;
        return dummy->next;
    }
};