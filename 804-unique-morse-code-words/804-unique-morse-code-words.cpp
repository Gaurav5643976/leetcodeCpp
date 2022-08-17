class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string str[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto i:words){
            string temp="";
            for(auto j:i){
                temp+=str[j-'a'];
            }
            st.insert(temp);
        }
        int ans=st.size();
        return ans;
    }
};