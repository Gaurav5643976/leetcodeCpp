class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        queue<int> q;
        vis[0]=true;
        for(auto i:rooms[0]){
            q.push(i);
            vis[i]=true;
        }
        while(!q.empty()){
            int element=q.front();
            //cout<<element<<" ";
            q.pop();
            // if(!vis[element]){
            //     vis[element]=true;
                for(auto i:rooms[element]){
                    if(!vis[i]){
                        vis[i]=true;
                        q.push(i);
                    }
                }
            // }
        }
        for(auto i:vis){
            //cout<<i<<" ";
            if(i==false){
                return false;
            }
        }
        //cout<<endl;
        return true;
    }
};