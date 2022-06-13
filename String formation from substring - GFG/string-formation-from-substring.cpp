// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    int n=s.size();
       for(int i=0;i<n;i++)
       {
           string subString=s.substr(0,i);
           int subSize=subString.size();
           if(n!=0 && subSize!=0 && n%subSize==0)
           {
               int count=0;
               int checkSize=n/subSize;
               string test="";
               while(count<checkSize)
               {
                   test+=subString;
                   if(test==s)
                   {
                       return 1;
                   }
                   count++;
               }
           }
       }
       return 0;
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
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends