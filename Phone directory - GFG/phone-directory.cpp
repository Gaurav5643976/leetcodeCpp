//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        string str="";
        vector<string> k(n,"");
        vector<vector<string>> ans;
        for(int i=0;i<s.length();i++)
        {
            str+=s[i];
            set<string> t;
            for(int j=0;j<n;j++)
            {
                k[j]+=contact[j][i];
                if(k[j]==str)
                {
                    t.insert(contact[j]);
                }
            }
            if(t.size()==0)
            {
                t.insert("0");
            }
            vector<string> vt;
            for(auto ele:t)
            {
                vt.push_back(ele);
            }
            ans.push_back(vt);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends