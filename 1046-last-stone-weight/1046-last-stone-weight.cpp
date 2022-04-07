class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq(stones.begin(),stones.end());
        while(pq.size()>=2){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y){
                pq.push(abs(x-y));
            }
        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    }
};