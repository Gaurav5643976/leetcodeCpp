// void postGreater(vector<int> h,int n,vector<int>& v){
//     stack<int> st;
//     for(int i=n-1;i>=0;i--){
//         if(!st.empty()){
//             if(st.top()>h[i]){
//                 v.push_back(st.top());
//             }
//             else{
//                 while(!st.empty() and st.top()<=h[i]){
//                     st.pop();
//                 }
//                 if(st.empty()){
//                     v.push_back(INT_MIN);
//                 }
//                 else{
//                     v.push_back(st.top());
//                 }
//             }
//         }
//         else{
//             v.push_back(INT_MIN);
//         }
//         st.push(h[i]);
//     }
// }
// void preGreater(vector<int> h,int n,vector<int>& v){
//     stack<int> st;
//     for(int i=0;i<n;i++){
//         if(!st.empty()){
//             if(st.top()>h[i]){
//                 v.push_back(st.top());
//             }
//             else{
//                 while(!st.empty() and st.top()<=h[i]){
//                     st.pop();
//                 }
//                 if(st.empty()){
//                     v.push_back(INT_MIN);
//                 }
//                 else{
//                     v.push_back(st.top());
//                 }
//             }
//         }
//         else{
//             v.push_back(INT_MIN);
//         }
//         st.push(h[i]);
//     }
// }
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> postGreaterElement(n),preGreaterElement(n);
        preGreaterElement[0]= height[0];
        for(int i=1;i<n;i++){
            preGreaterElement[i]=max(preGreaterElement[i-1],height[i]);
        }
        postGreaterElement[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            postGreaterElement[i]=max(postGreaterElement[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int mi=min(postGreaterElement[i],preGreaterElement[i])-height[i];
            if(mi>0){
                ans+=mi;
            }
        }
        return ans;
    }
};