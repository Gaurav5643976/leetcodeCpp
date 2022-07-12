// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findShortest(vector<vector<int>> &dp, string &S, string &T, int n, int m, int i, int j){
        //Why this?
        //This is because if we reach end of the string it means -> we were not able to find a subsequence which was not common
        if(i >= n){
            return 501;
        }
        //Now if i is not reached at end yet but j is reached we can definitely say that if now I take ith character in our subsequence, it will definitely create an uncommon subsequence
        if(j >= m){
            return 1;
        }
        //if we already know that for particular i, j position, what is the minimum length of the uncommon subsequence then return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //Suppose any of the above condition is not true, we will try to find current ith character in T string starting from j,
        int k = j;
        for(; k < m; k++){
            //if we find the character, it gives us two options -> either take that character in the uncommon subsequence and increase j to k + 1 and check to next character or don't add to subsequence and check for next character
            if(S[i] == T[k]){
                break;
            }
        }
        //or in case we did not find the ith character of S in T, then it's sure that we will get the uncommon subsequence by adding that character to our current ans
        if(k == m){
            return 1;
        }
        return dp[i][j] = min(findShortest(dp, S, T, n, m, i + 1, j), 1 + findShortest(dp, S, T, n, m, i + 1, k + 1));
    }
  
  
    int shortestUnSub(string S, string T) {
        int n = S.size();
        int m = T.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
        int ans = findShortest(dp, S, T, n, m, 0, 0);
        return ans >= 501 ? -1 : ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends