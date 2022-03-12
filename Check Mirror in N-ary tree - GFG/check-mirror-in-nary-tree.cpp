// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     int check(unordered_map <int,vector<int>> &a,unordered_map <int,vector<int>> &b,int s1,int s2)
       {
           if(s1!=s2 || a[s1].size()!=b[s2].size()){
            return 0;
           }
           int i=0,j=a[s1].size()-1;
           
           while(j>=0)
           {
              if(check(a,b,a[s1][i],b[s2][j])==0){
                  return 0;
              }
              i++;
              j--;
           }
           return 1;
       }
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
       unordered_map <int,vector<int>> a,b;
       for(int i=0;i<2*e;i+=2)
       {
           a[A[i]].push_back(A[i+1]);
           b[B[i]].push_back(B[i+1]);
       }
       return check(a,b,A[0],B[0]);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends