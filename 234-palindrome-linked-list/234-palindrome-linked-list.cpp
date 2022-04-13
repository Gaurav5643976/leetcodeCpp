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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp=head;
        int initial=0;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->next;
            initial++;
        }
        temp=head;
        initial/=2;
        while(temp!=NULL and initial--){
            ListNode* end=s.top();
            if(end->val!=temp->val){
                return false;
            }
            s.pop();
            temp=temp->next;
        }
        return true;
    }
};