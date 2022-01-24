// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx=-1;
        for(int i=N-1;i>=1;i--){
            if(arr[i]>arr[i-1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            sort(arr.begin(),arr.end());
            return arr;
        }
        int val=arr[idx-1],minGreaterVal=INT_MAX,index=-1;
        for(int i=idx;i<N;i++){
            if(arr[i]>val){
                if(arr[i]<minGreaterVal){
                    minGreaterVal=arr[i];
                    index=i;
                }
            }
        }
        //cout<<idx<<" "<<index<<endl;
        swap(arr[idx-1],arr[index]);
        sort(arr.begin()+idx,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends