// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        unordered_set<char> st;
        int n = a.length();
        for(int i = 0; i < n; i++)
        {
            char smallest = a[i];
            for(int j = i + 1; j < n; j++)
            {
                if(st.find(a[j]) == st.end() && smallest > a[j])
                {
                    smallest = a[j];
                }
            }
            if(smallest != a[i])
            {
                char toChange = a[i];
                for(int j = 0; j < a.length(); j++)
                {
                    if(a[j] == smallest)
                    {
                        a[j] = toChange;
                    }
                    else if(a[j] == toChange)
                    {
                        a[j] = smallest;
                    }
                }
                return a;
            }
            st.insert(a[i]);
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends