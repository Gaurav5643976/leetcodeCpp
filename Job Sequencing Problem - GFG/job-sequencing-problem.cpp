// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class Solution 
{
    public:
    struct DisjointSet
    {
        int *parent;
        DisjointSet(int n)
        {
            parent = new int[n+1];
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int find(int s)
        {
            if (s == parent[s])
                return s;
            return parent[s] = find(parent[s]);
        }
        void merge(int u, int v)
        {
            parent[v] = u;
        }
    };
    static bool cmp(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    int findMaxDeadline(struct Job arr[], int n)
    {
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, arr[i].dead);
        return ans;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    {  
        vector<int> ans(2,0);
        sort(arr, arr + n, cmp);
        int maxDeadline = findMaxDeadline(arr, n);
        DisjointSet ds(maxDeadline);
        for (int i = 0; i < n; i++)
        {
            int availableSlot = ds.find(arr[i].dead);
            if (availableSlot > 0)
            {
                ds.merge(ds.find(availableSlot - 1),availableSlot);
                ans[0]++,ans[1]+=arr[i].profit;
            }
        }
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends