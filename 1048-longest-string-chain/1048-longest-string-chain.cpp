class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const std::string& first, const std::string& second){
            return first.size() < second.size();
        });
        int ans=0;
        unordered_map<string,int> um;
        for(auto i:words){
            int longestChaincodeWithCurrentString=0;
            string str=i;
            for(int j=0;j<str.size();j++){
                string stringWithoutOneChar=str.substr(0,j)+str.substr(j+1);
                longestChaincodeWithCurrentString=max(longestChaincodeWithCurrentString,um[stringWithoutOneChar]+1);
            }
            um[i]=longestChaincodeWithCurrentString;
            ans=max(ans,longestChaincodeWithCurrentString);
        }
        return ans;
    }
};