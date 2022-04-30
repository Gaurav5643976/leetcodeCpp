// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    // Code here
	    vector<int> ans;
	    int n=str.size();
	    int m=Query.size();
	    vector<int> v[26];
	    for(int i=0;i<n;i++){
	        v[str[i]-'a'].push_back(i+1);
	    }
	    for(int i=0;i<m;i++){
	        int l=Query[i][0],r=Query[i][1];
	        int count=0;
	        for(int j=0;j<26;j++){
	            int mi=lower_bound(v[j].begin(),v[j].end(),l)-v[j].begin();
	            if(mi==v[j].size()){
	                continue;
	            }
	            mi=v[j][mi];
	            if(mi<=r){
	                count++;
	            }
	        }
	        ans.push_back(count);
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends