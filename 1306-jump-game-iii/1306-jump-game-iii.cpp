class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(arr[i]==0){
                return true;
            }
            int a=i+arr[i],b=i-arr[i];
            arr[i]=-1;
            if(a>=0 and a<n and arr[a]!=-1){
                q.push(a);
            }
            if(b>=0 and b<n and arr[b]!=-1){
                q.push(b);
            }
        }
        return false;
    }
};