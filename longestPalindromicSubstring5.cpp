// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case),


class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int mat[n][n];
        memset(mat,0,sizeof(mat));
        int maxLen=1;
        for(int i=0;i<n;i++){
            mat[i][i]=1;
        }
        int start=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                start=i;
                maxLen=2;
                mat[i][i+1]=1;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(s[i]==s[j] and mat[i+1][j-1]){
                    mat[i][j]=1;
                    if(k>maxLen){
                        maxLen=k;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
