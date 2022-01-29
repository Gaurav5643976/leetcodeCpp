// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans="",temp="";
        for(auto i:S){
            if(i=='.'){
                ans='.'+temp+ans;
                temp="";
            }
            else{
                temp+=i;
            }
        }
        ans=temp+ans;
        //reverse(ans.begin(),ans.end());
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends