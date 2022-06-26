class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int tempSum=0;
        for(int i=n-k;i<n;i++){
            tempSum+=cardPoints[i];
        }
        int maximumScore=tempSum;
        for(int i=n;i<n+k;i++){
            tempSum-=cardPoints[(i-k)%n];
            tempSum+=cardPoints[(i)%n];
            maximumScore=max(maximumScore,tempSum);
        }
        return maximumScore;
    }
};