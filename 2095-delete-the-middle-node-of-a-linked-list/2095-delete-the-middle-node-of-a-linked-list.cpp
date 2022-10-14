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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return NULL;
        }
        ListNode *sp=head,*fp=head,*t=NULL;
        while(fp and fp->next){
            t=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        t->next=sp->next;
        return head;
    }
};