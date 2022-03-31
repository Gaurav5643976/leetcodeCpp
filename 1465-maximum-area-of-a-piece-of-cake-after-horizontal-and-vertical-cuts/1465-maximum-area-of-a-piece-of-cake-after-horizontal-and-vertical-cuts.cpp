class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int n=horizontalCuts.size(),m=verticalCuts.size();
        unsigned long long maH=0,maV=0;
        for(int i=0;i<n-1;i++){
            if(maH<horizontalCuts[i+1]-horizontalCuts[i]){
                maH=horizontalCuts[i+1]-horizontalCuts[i];
            }
        }
        for(int i=0;i<m-1;i++){
            if(maV<verticalCuts[i+1]-verticalCuts[i]){
                maV=verticalCuts[i+1]-verticalCuts[i];
            }
        }
        unsigned long long ans=(maH*maV)%1000000007;
        return ans;
    }
};