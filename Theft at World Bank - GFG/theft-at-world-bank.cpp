// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	    long double ans=0;
	    vector<vector<long double>> vvld;
	    for(int i=0;i<N;i++){
	        long double we=w[i],pr=p[i];
	        if(floor(1.0*(sqrt(we)))!=ceil(1.0*(sqrt(we)))){
	            vvld.push_back({pr/we,pr,we});
	        }
	    }
	    sort(vvld.begin(),vvld.end());
	    reverse(vvld.begin(),vvld.end());
	    for(auto i:vvld){
	        //cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	        if(C>=i[2]){
	            ans+=i[1];
	            C-=i[2];
	        }
	        else{
	            ans+=(1.0*i[1]*C)/i[2];
	            C=0;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends