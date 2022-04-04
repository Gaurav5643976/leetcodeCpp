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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur=head,*pre=head;
        int count=k;
        while(--count){
            cur=cur->next;
        }
        ListNode *kth=cur;
        while(cur->next){
            pre=pre->next;
            cur=cur->next;
        }
        swap(pre->val,kth->val);
        return head;
    }
};