// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        int low=1,high=sum;
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            int m=mid;
            for(int i=0;i<N;i++){
                if(mid<arr[i]){
                    count=D+1;
                    break;
                }
                m=mid;
                while(i<N and m-arr[i]>=0){
                    m-=arr[i];
                    i++;
                }
                i--;
                count++;
            }
            if(count>D){
                low=mid+1;
            }
            else if(count<=D){
                high=mid;
            }
        }
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends