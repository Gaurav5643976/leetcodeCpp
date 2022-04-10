class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans=0;
        vector<int> v;
        for(auto i:ops){
            if(i=="+"){
                int n=v.size();
                v.push_back(v[n-1]+v[n-2]);
            }
            else if(i=="C"){
                v.pop_back();
            }
            else if(i=="D"){
                int n=v.size();
                v.push_back(2*v[n-1]);
            }
            else{
                v.push_back(stoi(i));
            }
        }
        for(auto i:v){
            ans+=i;
        }
        return ans;
    }
};