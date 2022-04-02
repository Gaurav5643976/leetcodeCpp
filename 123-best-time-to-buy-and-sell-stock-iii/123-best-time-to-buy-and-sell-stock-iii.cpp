class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        vector<int> profitTillToday(n);
        profitTillToday[0]=0;
        int buy=prices[0];
        for(int i=1;i<n;i++){
            profitTillToday[i]=max(profitTillToday[i-1],prices[i]-buy);
            buy=min(buy,prices[i]);
        }
        vector<int> profitAfterToday(n);
        profitAfterToday[n-1]=0;
        int sell=prices[n-1];
        for(int i=n-2;i>=0;i--){
            profitAfterToday[i]=max(profitAfterToday[i+1],sell-prices[i]);
            sell=max(sell,prices[i]);
        }
       for(int i=0;i<n;i++){
           maxProfit=max(maxProfit,profitTillToday[i]+profitAfterToday[i]);
       }
        return maxProfit;
    }
};