class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        using vi=vector<int>;
        vector<vi> dist(m,vi(n,INT_MAX));
        priority_queue<vi,vector<vi>, greater<vi>> pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        vector<vi> dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!pq.empty()){
            vi v=pq.top();
            pq.pop();
            if(v[0]>dist[v[1]][v[2]]){
                continue;
            }
            if(v[1]==m-1 and v[2]==n-1){
                return v[0];
            }
            for(auto i:dir){
                int x=v[1]+i[0],y=v[2]+i[1];
                if(x>=0 and x<m and y>=0 and y<n){
                    int tempDist=max(v[0],abs(heights[x][y]-heights[v[1]][v[2]]));
                    if(dist[x][y]>tempDist){
                        dist[x][y]=tempDist;
                        pq.push({tempDist,x,y});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};