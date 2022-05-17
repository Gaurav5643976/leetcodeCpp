// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to find the minimum element in sorted and rotated array.
int minNumber(int arr[], int low, int high)
   {
       int s = low;
       int e = high;
       int mid = s + (e-s)/2;
       while(s<e){
           if(arr[mid] >= arr[0])
               s = mid+1;
           else
               e = mid;
           
           mid = s + (e-s)/2;
       }
       if(arr[s]<arr[0])
           return arr[s];
       else
           return arr[0];
   }

// { Driver Code Starts.

int main()
{
	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i=0;i<n;++i)
			scanf("%d", &a[i]);	
	
		printf("%d\n", minNumber(a,0,n-1) );
	}
	return 0;
}  // } Driver Code Ends