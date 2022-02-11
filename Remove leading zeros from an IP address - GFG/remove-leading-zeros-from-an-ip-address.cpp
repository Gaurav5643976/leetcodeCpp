// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        //code here.
        string ans="",temp="";
        for(auto i:s){
            if(i=='.'){
                int j=0;
                while(temp[j]=='0'){
                    j++;
                }
                if(j>=temp.size()){
                    ans+="0.";
                }
                else{
                    ans+=temp.substr(j)+'.';
                }
                temp="";
            }
            else{
                temp+=i;
            }
        }
        int j=0;
        while(temp[j]=='0'){
            j++;
        }
        if(j>=temp.size()){
            ans+="0";
        }
        else{
            ans+=temp.substr(j);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends