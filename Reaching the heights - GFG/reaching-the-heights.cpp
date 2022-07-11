// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
     if(n==1){
         return {a[0]};
     }
    sort(a,a+n);
    vector<int> ans(n);
    int i=0,j=n-1,k=0,curLevel=0;
    while(i<=j){
        ans[k++]=a[j];
        ans[k++]=a[i];
        curLevel+=(a[j--]-a[i++]);
        if(curLevel<=0){
            return {-1};
        }
    }
    return ans;
}
