class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st,bankSet;
        for(auto i:wordList){
            bankSet.insert(i);
        }
        string dir="abcdefghijklmnopqrstuvwxyz";
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.insert(beginWord);
        while(!q.empty()){
            string str=q.front().first;
            int count=q.front().second;
            q.pop();
            if(str==endWord){
                return count;
            }
            for(int i=0;i<str.size();i++){
                for(auto j:dir){
                    if(str[i]!=j){
                        string temp=str;
                        temp[i]=j;
                        if(!st.count(temp) and bankSet.count(temp)){
                            st.insert(temp);
                            q.push({temp,count+1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};