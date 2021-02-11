// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.


class Solution {
public:
    bool isAnagram(string s, string t) {
        int S[26]={0},T[26]={0};
        for(auto i:s){
            S[i-'a']++;
        }
        for(auto i:t){
            T[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(S[i]!=T[i]){
                return false;
            }
        }
        return true;
    }
};