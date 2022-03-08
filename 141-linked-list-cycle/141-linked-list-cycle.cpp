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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode *slowPtr=head,*fastPtr=head->next;
        while(fastPtr and fastPtr->next){
            if(slowPtr==fastPtr){
                return true;
            }
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
        }
        return false;
    }
};