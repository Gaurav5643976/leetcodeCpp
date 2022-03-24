class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> st;
        for(auto i:forbidden){
            st.insert(i);
        }
        queue<vector<int>> q;
        q.push({0,1,0});
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            if(v[0]==x){
                return v[2];
            }
            if(st.find(v[0])!=st.end()){
                continue;
            }
            st.insert(v[0]);
            int backward=v[0]-b;
            if(v[1]!=0 and backward>=0){
                q.push({backward,0,v[2]+1});
            }
            int forward=v[0]+a;
            if(v[0]<=2000+b){
                q.push({forward,1,v[2]+1});
            }
        }
        return -1;
    }
};