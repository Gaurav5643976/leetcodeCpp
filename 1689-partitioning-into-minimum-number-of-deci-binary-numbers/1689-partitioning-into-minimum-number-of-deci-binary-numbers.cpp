class Solution {
public:
    int minPartitions(string n) {
        char c='0';
        for(auto i:n){
            c=max(c,i);
        }
        int ans=c-'0';
        return ans;
    }
};