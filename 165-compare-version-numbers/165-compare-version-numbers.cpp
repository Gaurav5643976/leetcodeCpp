class Solution {
public:
    void solve(string a, vector<int>& s){
        string temp="";
        for(auto i:a){
            if(i=='.'){
                s.push_back(stoi(temp));
                temp="";
            }
            else{
                temp+=i;
            }
        }
        s.push_back(stoi(temp));
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        solve(version1,v1);
        solve(version2,v2);
        int ma=max(v1.size(),v2.size());
        for(auto i:v1){
            cout<<i<<" ";
        }
        for(auto i:v2){
            cout<<i<<" ";
        }
        for(int i=0;i<ma;i++){
            if(v1.size()-1<i){
                if(v2[i]!=0){
                    return -1;
                }
            }
            else if(v2.size()-1<i){
                if(v1[i]!=0){
                    return 1;
                }
            }
            else if(v1[i]<v2[i]){
                return -1;
            }
            else if(v1[i]>v2[i]){
                return 1;
            }
        }
        return 0;
    }
};