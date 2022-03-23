class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(graph[i].size()==0){
                ans.push_back(i);
                st.insert(i);
            }
        }
        int sz=ans.size();
        while(1){
            for(int i=0;i<n;i++){
                bool flag=true;
                for(auto j:graph[i]){
                    if(st.find(j)==st.end()){
                        flag=false;
                        break;
                    }
                }
                if(flag and st.find(i)==st.end()){
                    ans.push_back(i);
                    st.insert(i);
                }
            }
            if(sz==ans.size()){
                break;
            }
            sz=ans.size();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};