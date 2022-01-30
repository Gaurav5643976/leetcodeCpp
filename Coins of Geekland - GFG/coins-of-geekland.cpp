// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int k){
        // Your code goes here
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==0 and j==0){
                    
                }
                else if(i==0){
                    mat[i][j]+=mat[i][j-1];
                }
                else if(j==0){
                    mat[i][j]+=mat[i-1][j];
                }
                else{
                    mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
                }
                //cout<<mat[i][j]<<" ";
            }
            //cout<<endl;
        }
        int ma=0;
        for(int i=k-1;i<N;i++){
            for(int j=k-1;j<N;j++){
                int ans=mat[i][j];
                if(i-k>=0 and j-k>=0){
                    ans+=mat[i-k][j-k];
                }
                if(i-k>=0 ){
                    ans-=mat[i-k][j];
                }
                if(j-k>=0){
                    ans-=mat[i][j-k];
                }
                ma=max(ans,ma);
            }
        }
        return ma;
    }  
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends