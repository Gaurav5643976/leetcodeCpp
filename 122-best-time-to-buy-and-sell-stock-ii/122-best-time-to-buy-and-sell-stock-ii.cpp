class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int buy=prices[i],sell=prices[i];
            while(i+1<n and prices[i+1]>sell){
                sell=prices[i+1];
                i++;
            }
            maxPro+=sell-buy;
            //cout<<sell<<" "<<buy<<endl;
        }
        return maxPro;
    }
};