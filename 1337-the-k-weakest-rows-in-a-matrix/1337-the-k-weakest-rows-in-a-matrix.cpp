class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        priority_queue<vector<int>, vector<vector<int>>> pq;
        for(int i=0;i<n;i++){
            int count=lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>())-mat[i].begin();
            pq.push({count,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            int t=pq.top()[1];
            ans.push_back(t);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};