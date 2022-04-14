/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *sP=head,*fP=head;
        while(fP and fP->next){
            sP=sP->next;
            fP=fP->next->next;
            if(sP==fP){
                ListNode* ansP=head;
                while(ansP!=sP){
                    sP=sP->next;
                    ansP=ansP->next;
                }
                return ansP;
            }
        }
        return NULL;
    }
};