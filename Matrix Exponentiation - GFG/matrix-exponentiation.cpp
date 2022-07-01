// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int m=1e9+7;
vector<vector<long long int>>matrixmulti(vector<vector<long long int>> &a, vector<vector<long long int>> &b){
    vector<vector<long long int>>c={{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][j]+=((a[i][k]%m)*b[k][j]%m)%m;
            }
        }
    }
    return c;
}
    int FindNthTerm(long long int n) {
        // Code here
     
       vector<vector<long long int>> mat = {{1,1},{1,0}};
       vector<vector<long long int>> res = {{1,1},{1,0}};
       while(n){
           if(n%2==1){
               res=matrixmulti(mat,res);
           }
           mat=matrixmulti(mat,mat);
           n=n>>1;
       }
       return res[0][1]%m;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends