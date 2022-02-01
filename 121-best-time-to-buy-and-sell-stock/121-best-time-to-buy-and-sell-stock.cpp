class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int sz=prices.size();
        int maxPrice=0;
        for(int i=sz-2;i>=0;i--){
            maxPrice=max(maxPrice,prices[i+1]);
            maxProfit=max(maxProfit,maxPrice-prices[i]);
        }
        return maxProfit;
    }
};