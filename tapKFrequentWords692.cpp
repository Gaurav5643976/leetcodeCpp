// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto i:words){
            if(m.find(i)!=m.end()){
                m[i]++;
            }
            else{
                m[i]=1;
            }
        }
        map<int,vector<string>> mp;
        for(auto i:m){
            mp[i.second].push_back(i.first);
        }
        vector<string> ans;
        int c=0;
        map<int,vector<string>>::reverse_iterator i;
        for(auto i=mp.rbegin();i!=mp.rend();i++){
            vector<string> v=i->second;
            sort(v.begin(),v.end());
            for(auto j:v){
                ans.push_back(j);
                c++;
                if(c==k){
                    break;
                }
            }
            if(c==k){
                break;
            }
        }
        return ans;
    }
};