// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long helper(string s,int k){
       if(s.size()==1){
           return 1ll;
       }
       long ans=0;
       string temp=s.substr(2,s.size()-2);
       for(int i=1;i<k;i++){
           ans+=helper(temp,k-i);
       }
       return ans;
   }
   long posIntSol(string s)
   {
       string k1="",k2="";
       for(int i=0;i<s.size();i++){
           if(s[i]=='='){
               break;
           }
           k2+=s[i];
       }
       for(int i=s.size()-1;i>=0;i--){
           if(s[i]=='='){
               break;
           }
           k1=s[i]+k1;
       }
       int k=stoi(k1);
       
       long ans=helper(k2,k);
       return ans;
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends