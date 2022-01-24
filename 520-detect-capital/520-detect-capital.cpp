class Solution {
public:
    bool isCapital(string str){
        for(auto i:str){
            if(islower(i)){
                return false;
            }
        }
        return true;
    }
    bool isSmall(string str){
        for(auto i:str){
            if(isupper(i)){
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(isCapital(word) or isSmall(word) or (isupper(word[0]) and isSmall(word.substr(1,word.size()-1))))        {
            return true;
        }
        return false;
    }
};