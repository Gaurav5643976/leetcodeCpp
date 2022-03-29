class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> um;
        for(auto i:time){
            um[i%60]++;
        }
        int ans=0;
        for(auto i:um){
            //cout<<i.first<<" "<<i.second<<endl;
            if(i.first==0 or i.first==30){
                long long c=i.second;
                ans+=c*(c-1)/2;
            }
            else{
                int p1=i.second,p2=um[60-i.first];
                ans+=p1*p2;
                um[i.first]=0;
                um[60-i.first]=0;
            }
        }
        return ans;
    }
};