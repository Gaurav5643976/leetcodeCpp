class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> freq;
        for(auto i:tasks){
            freq[i]++;
        }
        priority_queue<int,vector<int>> pq;
        for(auto i:freq){
            pq.push(i.second);
        }
        int ans=0;
        while(!pq.empty()){
            int time=0;
            vector<int> v;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int f=pq.top();
                    pq.pop();
                    time++;
                    v.push_back(f-1);
                }
            }
            for(auto i:v){
                if(i>0){
                    pq.push(i);
                }
            }
            ans+=pq.empty()?time:n+1;
        }
        return ans;
    }
};