class Solution {
public:
    int pivot(vector<int>& nums)
    {
        int l=0,r=nums.size()-1;
        int ans=0;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mid>0 && nums[mid]<nums[mid-1])
            {
                ans=mid;
                break;
            }
            else if(nums[r]<nums[mid])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        return ans;
    }
    
    bool searc(vector<int>& nums,int l,int r,int t)
     {
       
         while(l<=r)
         {
             int mid=l+(r-l)/2;
            if(nums[mid]==t)
            {
                return true;
            }
            else if(nums[mid]<t)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
         }
         return false;
     }

    
    bool search(vector<int>& nums, int target) {
        int p=pivot(nums);
        if(p==0)
        {
            for(int i:nums){
                if(i==target)
                    return true;
            }
            
            return false;
        }
        
        return searc(nums,0,p-1,target)||searc(nums,p,nums.size()-1,target);
    }
};