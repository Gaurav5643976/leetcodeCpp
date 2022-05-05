// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        // code here 
        string x = "";
        string y = S;
        for(int i=0;i<S.size()-1;i++)
        {
            x.push_back(S[i]);
            y.erase(0,1);
            int num1 = stoi(x);
            int num2 = stoi(y);
            if(num1%a==0&&num2%b==0)
            {
                return x+" "+y;
                
            }
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
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends