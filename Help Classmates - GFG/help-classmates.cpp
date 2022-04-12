// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> nums, int n) 
    { 
        // Your code goes here
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int index=i%n;
            if(!st.empty()){
                if(st.top()<nums[index]){
                    ans[index]=st.top();
                }
                else{
                    while(!st.empty() and st.top()>=nums[index]){
                        st.pop();
                    }
                    if(!st.empty() and st.top()<nums[index]){
                        ans[index]=st.top();
                    }
                }
            }
            st.push(nums[index]);
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}

  // } Driver Code Ends