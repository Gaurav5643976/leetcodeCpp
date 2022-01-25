class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3){
            return false;
        }
        bool st1=false,st2=false;
        int i=0;
        while(i+1<n and arr[i]<arr[i+1]){
            i++;
            st1=true;
        }
        while(i+1<n and arr[i]>arr[i+1] ){
            i++;
            st2=true;
        }
        //cout<<i;
        return st1 and st2 and i==n-1;
    }
};