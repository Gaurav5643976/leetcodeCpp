// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        int totalDistictElements=st.size();
        st.clear();
        unordered_map<int,int> um;
        int ans=0;
        int left=0,right=0;
        while(right<n){
            um[arr[right]]++;
            int currentSize=um.size();
            while(currentSize==totalDistictElements){
                ans+=n-right;
                if(um[arr[left]]==1){
                    um.erase(arr[left]);
                }
                else{
                    um[arr[left]]--;
                }
                left++;
                currentSize=um.size();
            }
            right++;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends