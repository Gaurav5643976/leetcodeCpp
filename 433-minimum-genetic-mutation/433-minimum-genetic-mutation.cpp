class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st,bankSet;
        for(auto i:bank){
            bankSet.insert(i);
        }
        string dir="ACGT";
        queue<pair<string,int>> q;
        q.push({start,0});
        st.insert(start);
        while(!q.empty()){
            string str=q.front().first;
            int mutationCount=q.front().second;
            q.pop();
            cout<<str<<" ";
            if(str==end){
                return mutationCount;
            }
            for(int i=0;i<8;i++){
                for(auto j:dir){
                    if(str[i]!=j){
                        string temp=str;
                        temp[i]=j;
                        if(!st.count(temp) and bankSet.count(temp)){
                            st.insert(temp);
                            q.push({temp,mutationCount+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};