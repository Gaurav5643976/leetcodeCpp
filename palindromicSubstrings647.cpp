// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

// Example 1:

// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
 

// Example 2:

// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Note:

// The input string length won't exceed 1000.


class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=n;
        int mat[n][n];
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++){
            mat[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                ans++;
                mat[i][i+1]=1;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(mat[i+1][j-1] && s[i]==s[j]){
                    mat[i][j]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};