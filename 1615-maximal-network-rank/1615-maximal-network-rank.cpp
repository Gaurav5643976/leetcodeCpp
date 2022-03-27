class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        vector<int> degree(n,0);
        set<pair<int,int>> st;
        for(auto i:roads){
            degree[i[0]]++;
            degree[i[1]]++;
            st.insert({i[0],i[1]});
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(degree[i]+degree[j]>ans){
                    ans=degree[i]+degree[j];
                    if(st.count({i,j}) or st.count({j,i})){
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};