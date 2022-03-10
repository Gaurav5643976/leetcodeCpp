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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        int sum=l1->val+l2->val;
        ListNode* temp=new ListNode(sum%10);
        ListNode* p=temp;
        int carry=sum/10;
        l1=l1->next;
        l2=l2->next;
        while(l1 and l2){
            sum=l1->val+l2->val+carry;
            p->next=new ListNode(sum%10);
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
            p=p->next;
        }
        while(l1){
            sum=l1->val+carry;
            p->next=new ListNode(sum%10);
            carry=sum/10;
            l1=l1->next;
            p=p->next;
        }
        while(l2){
            sum=l2->val+carry;
            p->next=new ListNode(sum%10);
            carry=sum/10;
            l2=l2->next;
            p=p->next;
        }
        if(carry){
             p->next=new ListNode(1);
        }
        return temp;
    }
};