class Solution {
public:
    void nextGreaterIndex(vector<int>& arr,int n,vector<int>& nge){
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                if(arr[st.top()]>arr[i]){
                    nge[i]=st.top();
                }
                else{
                    while(!st.empty() and arr[st.top()]<=arr[i]){
                        st.pop();
                    }
                    if(!st.empty() and arr[st.top()]>arr[i]){
                        nge[i]=st.top();
                    }
                }
            }
            st.push(i);
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> nge(n,n);
        nextGreaterIndex(nums,n,nge);
        vector<int> ans;
        int j=0;
        for(int i=0;i<=n-k;i++){
            if(j<i){
                j=i;
            }
            while(nge[j]<i+k){
                j=nge[j];
            }
            ans.push_back(nums[j]);
        }
        return ans;
    }
};