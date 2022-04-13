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
        stack<int> st1,st2,st3;
        ListNode* temp=l1;
        while(temp){
            st1.push(temp->val);
            temp=temp->next;
        }
        temp=l2;
        while(temp){
            st2.push(temp->val);
            temp=temp->next;
        }
        int sum=st1.top()+st2.top();
        st1.pop(),st2.pop();
        st3.push(sum%10);
        int carry=sum/10;
        while(!st1.empty() and !st2.empty()){
            sum=st1.top()+st2.top()+carry;
            st1.pop(),st2.pop();
            st3.push(sum%10);
            carry=sum/10;
        }
        while(!st1.empty()){
            sum=st1.top()+carry;
            st1.pop();
            st3.push(sum%10);
            carry=sum/10;
        }
         while(!st2.empty()){
            sum=st2.top()+carry;
            st2.pop();
            st3.push(sum%10);
            carry=sum/10;
        }
        if(carry){
            st3.push(1);
        }
        ListNode* head=new ListNode(st3.top());
        st3.pop();
        temp=head;
        while(!st3.empty()){
            temp->next=new ListNode(st3.top());
            st3.pop();
            temp=temp->next;
        }
        return head;
    }
};