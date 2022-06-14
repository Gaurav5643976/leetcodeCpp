// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
         int trailingZeros( int n){
          
          int ans  = 0 ;
          for( int  i = 5 , j = 1 ; i*j <= n ;j = j*5){
              ans = ans +  n / (i*j) ;
          }
          return ans ;
      }    
   
      int bs( int start , int end , int nzeros){
          
          int ans  =  0 ;
          int mid = (start + end )/2 ;
         
          while( start <= end){
              
              mid = (start + end )/2 ;
              
              if(trailingZeros(mid) < nzeros){
                  start = mid + 1 ;
              }
              else{
                  ans = mid ;
                  end = mid - 1 ;
              }
          }
          
         return ans ; 
      }    
   
       int findNum(int n)
       {
       //complete the function here
       
       return bs(0 ,  5 * n, n);    //
       }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends