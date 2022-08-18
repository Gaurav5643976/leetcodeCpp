class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int freq[100001]={0};
        for(auto i:arr){
            freq[i]++;
        }
        sort(freq,freq+100001);
        int count=0,i=100000;
        while(count<n/2){
            count+=freq[i];
            i--;
        }
        return 100000-i;
    }
};