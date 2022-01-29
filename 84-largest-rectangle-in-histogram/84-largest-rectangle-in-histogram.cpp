class Solution {
public:
    void nearestSmallerToLeft(vector<int> h,vector<int>& l){
        stack<pair<int,int>> st;
        for(int i=0;i<h.size();i++){
            if(st.size()==0){
                l.push_back(-1);
            }
            else if(st.top().first<h[i]){
                l.push_back(st.top().second);
            }
            else if(st.top().first>=h[i]){
                while(st.size()>0 and st.top().first>=h[i]){
                    st.pop();
                }
                if(st.size()==0){
                    l.push_back(-1);
                }
                else{
                    l.push_back(st.top().second);
                }
            }
            st.push({h[i],i});
        }
    }
    void nearestSmallerToRight(vector<int> h,vector<int>& r){
        stack<pair<int,int>> st;
        int n=h.size();
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                r.push_back(n);
            }
            else if(st.top().first<h[i]){
                r.push_back(st.top().second);
            }
            else if(st.top().first>=h[i]){
                while(st.size()>0 and st.top().first>=h[i]){
                    st.pop();
                }
                if(st.size()==0){
                    r.push_back(n);
                }
                else{
                    r.push_back(st.top().second);
                }
            }
            st.push({h[i],i});
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left,right;
        nearestSmallerToLeft(heights,left);
        nearestSmallerToRight(heights,right);
        reverse(right.begin(),right.end());
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};