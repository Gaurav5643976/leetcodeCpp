// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        int cntDup = 0;
        map<int,int> mapX, mapY;
        map<pair<int,int>, bool> mp;
        for(int i=0; i<N; i++)
        {
            mapX[X[i]]++;
            mapY[Y[i]]++;
            
            if(mp[{X[i],Y[i]}]){
                cntDup++;
            }
            else{
                mp[{X[i],Y[i]}] = true;
            }
        }
        int ans = 0;
        for(auto it : mapX)
        {
            int cnt = it.second;
            ans += (cnt*(cnt-1))/2;
        }
        for(auto it : mapY)
        {
            int cnt = it.second;
            ans += (cnt*(cnt-1))/2;
        }
        return ans-2*cntDup;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends