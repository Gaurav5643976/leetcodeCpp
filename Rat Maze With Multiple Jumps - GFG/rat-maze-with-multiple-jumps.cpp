// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool getAns(vector< vector<int> > &mat, int& r, int &c, int i, int j, vector< vector<int> >& ans){
    ans[i][j] = 1 ;
    if(i == r-1 && j == c-1)
        return true ;
    
    for(int jump = 1 ; jump <= mat[i][j] ; jump++){
        if(j+jump < c && getAns(mat,r,c,i,j+jump,ans))
            return true ;
        
        if(i + jump < r && getAns(mat,r,c,i+jump,j,ans))
            return true ;
    }
    
    ans[i][j] = 0 ;
    return false ;
}


vector<vector<int>> ShortestDistance(vector<vector<int>>&mat){
    int r = mat.size(), c = mat[0].size() ;
    
    vector< vector<int>> ans(r, vector<int>(c)) ;
    
    if(getAns(mat,r,c,0,0,ans))
        return ans ;
        
    return {{-1}} ;
    
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends