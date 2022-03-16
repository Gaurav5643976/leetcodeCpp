// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(vector<int>& A,int i,vector<vector<int>>& s,vector<int> v){
        int n=A.size();
        if(i>=n){
            s.push_back(v);
            return;
        }
        solve(A,i+1,s,v);
        v.push_back(A[i]);
        solve(A,i+1,s,v);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> ans;
        //set<vector<int>> s;
        //sort(A.begin(),A.end());
        vector<int> v;
        solve(A,0,ans,v);
        // for(auto i:s){
        //     ans.push_back(i);
        // }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends