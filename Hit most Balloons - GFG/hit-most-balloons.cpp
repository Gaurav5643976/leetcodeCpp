// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans=0;
        for(int i=0;i<N;i++){
            unordered_map<double,int> um;
            int same=1;
            for(int j=i+1;j<N;j++){
                if(arr[i].first==arr[j].first and arr[i].second==arr[j].second){
                    same++;
                }
                else if(arr[i].first==arr[j].first){
                    um[INT_MAX]++;
                }
                else{
                    double slope=(double)(arr[i].second-arr[j].second)/(double)(arr[i].first-arr[j].first);
                    um[slope]++;
                }
            }
            int temp=0;
            for(auto j:um){
                temp=max(j.second,temp);
            }
            ans=max(ans,temp+same);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends