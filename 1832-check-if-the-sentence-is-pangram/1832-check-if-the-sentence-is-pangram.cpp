class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26,0);
        for(auto i:sentence){
            freq[i-'a']++;
        }
        for(auto i:freq){
            if(!i){
                return false;
            }
        }
        return true;
    }
};