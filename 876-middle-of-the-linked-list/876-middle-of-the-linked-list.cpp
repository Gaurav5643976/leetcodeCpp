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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode *sP=head,*fP=head;
        while(fP and fP->next){
            fP=fP->next->next;
            sP=sP->next;
        }
        return sP;
    }
};