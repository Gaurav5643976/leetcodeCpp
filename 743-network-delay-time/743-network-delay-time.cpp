class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using pi = pair<int,int>;
        vector<vector<pi>> adjList(n,vector<pi>());
        for(auto i:times){
            adjList[i[0]-1].push_back({i[1]-1,i[2]});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({k-1,0});
        dist[k-1]=0;
        while(!pq.empty()){
            pi p=pq.top();
            pq.pop();
            for(pi nbr:adjList[p.first]){
                if(dist[nbr.first]>p.second+nbr.second){
                    dist[nbr.first]=p.second+nbr.second;
                    pq.push({nbr.first,dist[nbr.first]});
                }
            }
        }
        int maxDist=0;
        for(auto i:dist){
            maxDist=max(maxDist,i);
        }
        if(maxDist==INT_MAX){
            return -1;
        }
        return maxDist;
    }
};