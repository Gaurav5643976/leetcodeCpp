// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k)
    {
        //code here
        long long ans=0;
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            int mod=A[i]%k;
            um[mod]++;
        }
        for(auto i:um){
            int req=k-i.first;
            //cout<<i.first<<" "<<i.second<<" ";
            if(req==i.first or i.first==0 or req==0){
                ans+=i.second*(i.second-1)/2;
                um[i.first]=0;
            }
            else if(um.find(req)!=um.end()){
                ans+=i.second*um[req];
                um[req]=0;
            }
        }
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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends