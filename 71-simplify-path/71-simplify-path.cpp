class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        string temp="";
        for(auto i:path){
            if(i=='/'){
                dir.push_back(temp);
                temp="";
            }
            else{
                temp+=i;
            }
        }
        dir.push_back(temp);
        int n=dir.size();
        for(int i=0;i<n;i++){
            if(dir[i]=="" or dir[i]=="."){
                dir.erase(dir.begin()+i);
                i--,n--;
            }
            else if(dir[i]==".."){
                dir.erase(dir.begin()+i);
                i--,n--;
                if(i>=0){
                    dir.erase(dir.begin()+i);
                    i--,n--;
                }
            }
        }
        string ans="";
        for(auto i:dir){
            ans+='/'+i;
        }
        if(ans==""){
            ans="/";
        }
        return ans;
    }
};