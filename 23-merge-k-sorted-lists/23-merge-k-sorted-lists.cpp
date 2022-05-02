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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        vector<vector<int>> list;
        for(int i=0;i<n;i++){
            vector<int> v;
            ListNode* temp=lists[i];
            while(temp){
                v.push_back(temp->val);
                temp=temp->next;
            }
            list.push_back(v);
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            int sz=list[i].size();
            if(sz>0){
                pq.push({list[i][0],i,0});
            }
        }
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
            temp->next=new ListNode(v[0]);
            temp=temp->next;
            if(v[2]+1<list[v[1]].size()){
                pq.push({list[v[1]][v[2]+1],v[1],v[2]+1});
            }
        }
        return head->next;
    }
};