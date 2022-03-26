class Solution {
public:
    unordered_set<string> generateNext(string str){
        unordered_set<string> st;
        string temp=str;
        for(int i=0;i<4;i++){
            char c=temp[i];
            temp[i]=(c=='9'?'0':c+1);
            st.insert(temp);
            string b=str;
            temp[i]=(c=='0'?'9':c-1);
            st.insert(temp);
            temp[i]=c;
        }
        return st;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(),deadends.end());
        string start="0000";
        if(deadSet.count(start) or deadSet.count(target)){
            return -1;
        }
        queue<pair<string,int>> q;
        q.push({start,0});
        deadSet.insert(start);
        while(!q.empty()){
            string cur=q.front().first;
            int turns=q.front().second;
            q.pop();
            if(cur==target){
                return turns;
            }
            for(auto i:generateNext(cur)){
                if(!deadSet.count(i)){
                    q.push({i,turns+1});
                    deadSet.insert(i);
                }
            }
        }
        return -1;
    }
};