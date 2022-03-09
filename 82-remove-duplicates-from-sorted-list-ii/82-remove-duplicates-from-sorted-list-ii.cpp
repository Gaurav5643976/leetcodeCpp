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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode *q=NULL,*pre=head,*cur=head->next;
        while(cur and pre->val==cur->val){
            while(cur and pre->val==cur->val){
                cur=cur->next;
            }
            head=cur;
            if(cur){
                pre=cur;
                cur=cur->next;
            }
        }
        while(cur){
            if(pre->val==cur->val){
                while(cur and pre->val==cur->val){
                    cur=cur->next;
                }
                q->next=cur;
            }
            else{
                q=pre;
            }
            pre=cur;
            if(cur){
                cur=cur->next; 
            }
        }
        return head;
    }
};