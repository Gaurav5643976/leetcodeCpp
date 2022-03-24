class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> st,vis;
        for(auto i:forbidden){
            st.insert(i);
        }
        queue<vector<int>> q;
        q.push({0,1,0});
        vis.insert(0);
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            if(v[0]==x){
                return v[2];
            }
            int backward=v[0]-b;
            if(v[1]!=0 and backward>=0 and st.find(backward)==st.end() and vis.find(backward)==vis.end()){
                q.push({backward,0,v[2]+1});
                vis.insert(backward);
            }
            int forward=v[0]+a;
            if(forward<=10001 and st.find(forward)==st.end() and vis.find(forward)==vis.end()){
                q.push({forward,1,v[2]+1});
                vis.insert(forward);
            }
        }
        return -1;
    }
};