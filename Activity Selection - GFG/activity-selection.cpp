// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code heret
        vector<vector<int>> v(n,vector<int>(2));
        for(int i=0;i<n;i++){
             v[i][0]=end[i];
             v[i][1]=start[i];
        }
        sort(v.begin(),v.end());
        int ans=1;
        int a=v[0][0],b=v[0][1];
        for(int i=1;i<n;i++){
            if(v[i][1]>a){
                ans++;
                a=v[i][0];
                b=v[i][1];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends