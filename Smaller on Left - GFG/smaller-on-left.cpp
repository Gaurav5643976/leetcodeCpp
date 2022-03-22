// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends

// void smallerOnLeft(int arr[],int n,vector<int>& ans){
//     stack<int> st;
//     for(int i=0;i<n;i++){
//         if(!st.empty()){
//             if(st.top()<arr[i]){
//                 ans[i]=st.top();
//             }
//             else{
//                 while(!st.empty() and st.top()>=arr[i]){
//                     st.pop();
//                 }
//                 if(!st.empty()){
//                     ans[i]=st.top();
//                 }
//             }
//         }
//         st.push(arr[i]);
//     }
// }
vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    vector<int> ans(n,-1);
    set<int> st;
    for(int i=0;i<n;i++){
        auto itr=st.lower_bound(arr[i]);
        if(itr!=st.begin()){
            itr--;
            ans[i]=*itr;
        }
        st.insert(arr[i]);
    }
    return ans;
}