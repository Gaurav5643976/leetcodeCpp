class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int edgesCount=edges.size();
        using pid=pair<int,double>;
        vector<vector<pid>> adjList(n,vector<pid>());
        for(int i=0;i<edgesCount;i++){
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dist(n,0);
        priority_queue<pid,vector<pid>,greater<pid>> pq;
        pq.push({start,1});
        dist[start]=1;
        while(!pq.empty()){
            pid p=pq.top();
            pq.pop();
            for(auto& [nbr,weight]:adjList[p.first]){
                if(dist[nbr]<p.second*weight){
                    dist[nbr]=p.second*weight;
                    pq.push({nbr,dist[nbr]});
                }
            }
        }
        // for(auto i:dist){
        //     cout<<i<<" ";
        // }
        return dist[end];
    }
};