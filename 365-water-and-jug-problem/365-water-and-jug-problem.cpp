class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z){
            return false;
        }
        unordered_set<int> st;
        queue<int> q;
        q.push(0);
        st.insert(0);
        vector<int> dir={x,-x,y,-y};
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(f==z){
                return true;
            }
            for(auto i:dir){
                int val=i+f;
                if(val>=0 and val<=x+y and st.find(val)==st.end()){
                    st.insert(val);
                    q.push(val);
                }
            }
        }
        return false;
    }
};