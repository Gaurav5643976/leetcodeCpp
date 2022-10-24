class Solution {
public:
    bool checkUniqueCharString(string s){
        if(s.size()>26){
            return false;
        }
        int freq[26]={0};
        for(auto i:s){
            freq[i-'a']++;
            if(freq[i-'a']>1){
                return false;
            }
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        vector<string> ansList;
        int ans=0;
        ansList.push_back("");
        for(auto i:arr){
            if(!checkUniqueCharString(i)){
                continue;
            }
            vector<string> newAnsListWithCurrStr;
            for(auto j:ansList){
                string temp=j+i;
                if(checkUniqueCharString(temp)){
                    newAnsListWithCurrStr.push_back(temp);
                    int sz=temp.size();
                    ans=max(ans,sz);
                }
            }
            for(auto j:newAnsListWithCurrStr){
                ansList.push_back(j);
            }
        }
        return ans;
    }
};