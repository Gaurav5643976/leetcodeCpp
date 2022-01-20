class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            for(auto i:piles){
                count+=i/mid;
                if(i%mid){
                    count++;
                }
            }
            if(count<=h){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};