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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* l=new ListNode();
        if(l1->val<l2->val){
            l->val=l1->val;
            l->next=merge(l1->next,l2);
        }
        else{
            l->val=l2->val;
            l->next=merge(l1,l2->next);
        }
        return l;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode *pre=NULL,*slow=head,*fast=head;
        while(fast and fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return merge(l1,l2);
    }
};