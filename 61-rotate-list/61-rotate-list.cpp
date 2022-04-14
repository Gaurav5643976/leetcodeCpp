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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 or head==NULL or head ->next==NULL){
            return head;
        }
        int noOfNodes=0;
        ListNode* temp=head;
        while(temp){
            noOfNodes++;
            temp=temp->next;
        }
        k%=noOfNodes;
        if(k==0){
            return head;
        }
        int breakPoint=noOfNodes-k;
        ListNode *cur=head,*pre=NULL;
        while(cur and breakPoint--){
            pre=cur;
            cur=cur->next;
        }
        pre->next=NULL;
        ListNode* ans=cur;
        while(cur){
            pre=cur;
            cur=cur->next;
        }
        pre->next=head;
        return ans;
    }
};