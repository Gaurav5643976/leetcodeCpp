// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
        int n=s1.size(),m=s2.size();
        vector<int> A1,B1,A2,B2;
        string a,b;
        for(int i=0;i<n;i++){
            if(s1[i]!='#'){
                a+=s1[i];
                if(s1[i]=='A'){
                    A1.push_back(i);
                }
                else{
                    B1.push_back(i);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(s2[i]!='#'){
                b+=s2[i];
                if(s2[i]=='A'){
                    A2.push_back(i);
                }
                else{
                    B2.push_back(i);
                }
            }
        }
        if(a!=b or A1.size()!=A2.size() or B1.size()!=B2.size()){
            return "No";
        }
        for(int i=0;i<A1.size();i++){
            if(A1[i]<A2[i]){
                return "No";
            }
        }
        for(int i=0;i<B1.size();i++){
            if(B1[i]>B2[i]){
                return "No";
            }
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends