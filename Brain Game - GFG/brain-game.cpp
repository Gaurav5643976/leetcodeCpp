// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    bool brainGame(vector<int>nums) {
    int dp[1005] = {0};
    dp[1] = dp[2] = 0;
    
    // dp[i] stores maximum moves posssible to break a number 
    // till no move further possible
    // Eg: 12 divisors are 2, 3, 4, 6 
    // it can be broke as 12 -> 6 -> 2/3, 12 -> 4 -> 2
    // or 12 -> 2 / 3, max two numbers are between 
    // the path to completely break 12
    for(int i = 3; i <= 1000; i++)
    {
        for(int j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                dp[i] = max(dp[i], 1 + max(dp[i / j], dp[j]));
            }
        }
    }
    
    // Now, consider the moves as piles of stone i.e, 
    // Game of Nim, if xor is positive player 1 wins
    int x = 0;
    for(auto num: nums)
    {
        x = x xor dp[num];
    }
    return x > 0;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends