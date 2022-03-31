class Solution {
public:
    bool isOkay(vector<int>& q,int m,int mid){
        int count=0;
        for(auto i:q){
            count+=i/mid;
            if(i%mid){
                count++;
            }
        }
        return count<=m;
    }
    int binarySearch(vector<int>& q,int low,int high,int m){
        int ans=high;
        while(low<high){
            int mid=low+(high-low)/2+1;
            if(isOkay(q,m,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        if(isOkay(q,m,low)){
            ans=low;
        }
        return ans;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1,high=*max_element(quantities.begin(),quantities.end());
        return binarySearch(quantities,low,high,n);
    }
};