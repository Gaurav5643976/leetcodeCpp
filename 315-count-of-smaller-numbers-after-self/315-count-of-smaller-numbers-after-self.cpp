class Solution {
public:
    void merge(vector<pair<int,int>> &v,vector<int> &ans,int left,int mid,int right)
{
        int i=left,j=mid+1,k=0;
        vector<pair<int,int>> temp(right-left+1);
        // sorting in descending order
        while(i<=mid && j<=right)
        {
            if(v[i].first>v[j].first)
            {
                ans[v[i].second]+=(right-j+1);
                temp[k++]=v[i++];
            }
            else{
                temp[k++]=v[j++];
            }    
        }
        while(i<=mid){
            temp[k++]=v[i++];
        }
        while(j<=right){
            temp[k++]=v[j++];
        }
        k=0;
        for(i=left;i<=right;i++){
            v[i]=temp[k++];
        }
    }
    void mergeSort(vector<pair<int,int>> &v,vector<int> &ans,int left,int right)
    {
        if(left<right)
        {
            int mid=left+(right-left)/2;
            mergeSort(v,ans,left,mid);
            mergeSort(v,ans,mid+1,right);
            merge(v,ans,left,mid,right);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
	    vector<pair<int,int>> v;
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    mergeSort(v,ans,0,n-1);
	    return ans;
    }
};