// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i:s){
            if(m.find(i)!=m.end()){
                m[i]++;
            }
            else{
                m[i]=1;
            }
        }
        vector<pair<int,char>> v;
        for(auto i:m){
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.rbegin(), v.rend());
        int n=v.size();
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].first;j++){
                ans+=v[i].second;
            }
        }
        return ans;
    }
};