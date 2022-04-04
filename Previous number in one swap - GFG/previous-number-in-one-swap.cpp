// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string S){
        // code here 
        int n=S.size();
        bool flag=false;
        for(int i=n-1;i>=1;i--){
            if(S[i-1]>S[i]){
                int index=i;
                for(int j=i;j<n;j++){
                    if(S[j]<S[i-1] and S[j]>S[index]){
                        index=j;
                    }
                }
                if(!(index==1 and S[index]=='0')){
                    flag=true;
                    swap(S[i-1],S[index]);
                    break;
                }
            }
        }
        if(flag){
            return S;
        }
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends