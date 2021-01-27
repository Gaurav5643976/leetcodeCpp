// You have a list of words and a pattern, and you want to know which words in words matches the pattern.

// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

// (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

// Return a list of the words in words that match the given pattern. 

// You may return the answer in any order.

 

// Example 1:

// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
// since a and b map to the same letter.
 

// Note:

// 1 <= words.length <= 50
// 1 <= pattern.length = words[i].length <= 20

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,string> m;
        for(int i=0;i<26;i++){
            m[char(97+i)]="";
        }
        int n=pattern.size();
        for(int i=0;i<n;i++){
            m[pattern[i]]+=to_string(i);
        }
        set<string> s;
        for(auto i:m){
            s.insert(i.second);
        }
        vector<string> ans;
        for(auto i:words){
            unordered_map<char,string> mp;
            for(int j=0;j<26;j++){
                mp[char(97+j)]="";
            }
            string str=i;
            int l=str.size();
            for(int j=0;j<l;j++){
                mp[str[j]]+=to_string(j);
            }
            set<string> st;
            for(auto j:mp){
                st.insert(j.second);
            }
            if(st==s){
                ans.push_back(i);
            }
        }
        return ans;
    }
};