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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==1){
            return head;
        }
        ListNode *temp=head;
        int count=0;
        while(count<k){
            if(temp==NULL){
                return head;
            }
            count++;
            temp=temp->next;
        }
        ListNode *cur=head,*pre=NULL,*nxt=NULL;
        count=0;
        while(cur and count<k){
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
            count++;
        }
        head->next=reverseKGroup(nxt,k);
        return pre;
    }
};