class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0,ma=0;
        for(int i=n-k;i<n+k;i++){
            while(i<n){
                sum+=cardPoints[i];
                i++;
            }
            ma=max(ma,sum);
            sum-=cardPoints[i-k];
            sum+=cardPoints[i%n];
        }
        ma=max(ma,sum);
        return ma;
    }
};