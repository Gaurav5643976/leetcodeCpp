// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int calculate(int a[], int n)
{
    // Complete the function
    long long int ans=0;
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        int firstIndex=lower_bound(a,a+n,a[i])-a;
        long long len=i-firstIndex+1;
        ans+=len*(len-1)/2;
        i=firstIndex;
    }
    return ans;
}
