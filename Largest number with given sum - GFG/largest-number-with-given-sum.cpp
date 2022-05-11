// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        string ans="";
        int m=n;
        while(m--){
            ans+='0';
        }
        int i=0;
        while(sum>0 and i<n){
            int mi=min(9,sum);
            sum-=mi;
            ans[i]=char(mi+'0');
            i++;
        }
        if(sum>0){
            return "-1";
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends