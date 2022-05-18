// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(string S,int index,vector<string>& ans,string str){
        if(index>=S.size()){
            if(index==S.size()){
                ans.push_back(str);
            }
            return;
        }
        if(index+1<S.size()){
            string withSpace=str+S[index]+" ";
            solve(S,index+1,ans,withSpace);
        }
        str+=S[index];
        solve(S,index+1,ans,str);
        
    }
    vector<string> permutation(string S){
        // Code Here
        vector<string> ans;
        string str="";
        solve(S,0,ans,str);
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends