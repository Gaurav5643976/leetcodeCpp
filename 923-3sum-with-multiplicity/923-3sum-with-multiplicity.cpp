class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        set<vector<long long>> st;
        unordered_map<long long,long long> um;
        for(auto i:arr){
            um[i]++;
        }
        long long ans=0;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            if(arr[i]>target){
                break;
            }
            if(i>0 and arr[i]==arr[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                long long a=arr[i],b=arr[j],c=arr[k];
                if(st.find({a,b,c})!=st.end()){
                    j++;
                    continue;
                }
                int sum=a+b+c;
                if(sum==target){
                    st.insert({a,b,c});
                    if(a==b and b==c){
                        long long n=um[a];
                        ans+=n*(n-1)*(n-2)/6;
                    }
                    else if(a==b and b!=c){
                        long long n=um[a];
                        ans+=(n*(n-1)/2)*um[c];
                    }
                    else if(a!=b and b==c){
                        long long n=um[b];
                        ans+=(n*(n-1)/2)*um[a];
                    }
                    else if(a!=b and b!=c){
                        ans+=um[a]*um[b]*um[c];
                    }
                    ans%=1000000007;
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return (int)ans;
    }
};