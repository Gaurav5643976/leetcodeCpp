// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        int freq[26]={0},sum=0;
        for(auto i:str){
            if(i>='A' and i<='Z'){
                freq[i-'A']++;
            }
            else{
                sum+=i-'0';
            }
            
        }
        string ans="";
        for(int i=0;i<26;i++){
            while(freq[i]--){
                ans+='A'+i;
            }
        }
        ans+=to_string(sum);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends