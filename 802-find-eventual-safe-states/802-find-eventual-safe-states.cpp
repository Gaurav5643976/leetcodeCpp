class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        unordered_set<int> st;
        unordered_map<int,vector<int>> um;
        for(int i=0;i<n;i++){
            if(graph[i].size()==0){
                ans.push_back(i);
                st.insert(i);
            }
            else{
                um[i]=graph[i];
            }
        }
        int sz=ans.size();
        while(1){
            int added=-1;
            for(auto itr:um){
                int i=itr.first;
                bool flag=true;
                for(auto j:itr.second){
                    if(st.find(j)==st.end()){
                        flag=false;
                        break;
                    }
                }
                if(flag and st.find(i)==st.end()){
                    ans.push_back(i);
                    st.insert(i);
                    added=i;
                }
            }
            if(added!=-1){
                um.erase(added);
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