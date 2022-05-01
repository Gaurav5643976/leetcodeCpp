// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    vector<bool> checkPrime(n+1,true);
	    vector<int> prime;
	    checkPrime[0]=false;
	    checkPrime[1]=false;
	    for(int i=2;i<=n;i++){
	        if(checkPrime[i]){
	            prime.push_back(i);
	        }
	        for(int j=2*i;j<=n;j+=i){
	            checkPrime[j]=false;
	        }
	    }
	    int ans=0;
	    for(int i=1;i<prime.size();i++){
	        int sum=prime[i]+2;
	        if(sum<=n and checkPrime[sum]){
	            ans++;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends