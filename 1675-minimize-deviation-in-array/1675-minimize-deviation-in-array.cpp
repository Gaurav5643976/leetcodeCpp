class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int m=INT_MAX,diff=INT_MAX;
        for(auto i:nums){
            if(i&1){
                i*=2;
            }
            m=min(m,i);
            pq.push(i);
        }
        while(pq.top()%2==0){
            int mx=pq.top();
            pq.pop();
            diff=min(diff,mx-m);
            m=min(m,mx/2);
            pq.push(mx/2);
        }
        return min(diff,pq.top()-m);
    }
};