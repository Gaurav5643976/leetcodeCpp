class Solution {
public:
    void solve(int freq[],int c){
        while(c!=0){
            int r=c%10;
            //cout<<r<<" ";
            freq[r]++;
            c/=10;
        }
    }
    bool reorderedPowerOf2(int m) {
        int arr[10]={0};
        solve(arr,m);
        int v=1;
        vector<int> num;
        num.push_back(1);
        while(v<=1e9){
            v*=2;
            num.push_back(v);
        }
        int n=num.size();
        for(int i=0;i<n;i++){
            int freq[10]={0};
            solve(freq,num[i]);
            for(int j=0;j<10;j++){
                if(freq[j]!=arr[j]){
                    break;
                }
                if(j==9){
                    return true;
                }
            }
        }
        return false;
    }
};