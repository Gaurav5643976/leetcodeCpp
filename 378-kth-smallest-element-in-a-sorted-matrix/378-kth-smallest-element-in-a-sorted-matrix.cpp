class Solution {
public:
    int getElementGreaterThan_K(vector<vector<int>>& mat,int n,int mid){
        int ans=0;
        for(int i=0;i<n;i++){
            if(mat[i][0]>mid){
                return ans;
            }
            if(mat[i][n-1]<=mid){
                ans+=n;
                continue;
            }
            int greaterThan=0;
            for(int j=n/2;j>=1;j/=2){
                while(greaterThan+j<n and mat[i][greaterThan+j]<=mid){
                    greaterThan+=j;
                }
            }
            ans+=greaterThan+1;
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int first=matrix[0][0],last=matrix[n-1][n-1];
        while(first<=last){
            int mid=first+(last-first)/2;
            int elementGreaterThan_K=getElementGreaterThan_K(matrix,n,mid);
            if(elementGreaterThan_K>=k){
                last=mid-1;
            }
            else{
                first=mid+1;
            }
        }
        return first;
    }
};