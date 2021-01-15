// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

// Example 1:

// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
// Example 2:

// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// Example 3:

// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
// 1 <= x <= 109

//Solution1: using binary search in O(nlogn)
class Solution {
public:
    int binarySearch(int A[], int l, int r, int val){
        if(r>=l){
            int mid=l+(r-l)/2;
            if(A[mid]==val){
                return mid;
            }
            if(A[mid]>val){
                return binarySearch(A, l, mid-1, val);
            }
            return binarySearch(A, mid+1, r, val);
        }
        return -1;
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int pre[n+5];
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
            //cout<<pre[i]<<" ";
        }
        int ans=INT_MAX;
        if(binarySearch(pre,0,n,x)!=-1){
            ans=binarySearch(pre,0,n,x);
        }
        for(int i=n-1;i>0;i--){
            int y=pre[n]-pre[i];
            if(x-y>=0){
                int indx=binarySearch(pre,0,i,x-y);
                if(indx!=-1){
                    ans=min(ans,n-i+indx);
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};


// Solution2: It can be done using a map instead of prefix array with complexity O(n)
