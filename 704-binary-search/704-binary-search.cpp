class Solution {
public:
    
    int bs(int l, int h, int x,vector<int> nums,int mid)
    {
        if(nums[mid] ==x)
            return mid;
        
        if(l>h)
            return -1;
        
        mid = (l+h)/2;
        if(nums[mid]<x)
        return bs(mid+1,h,x,nums,mid);
        else
        return bs(l,mid-1,x,nums,mid);
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int h = nums.size()-1;
        int mid = h/2;
        return bs(0,h,target,nums,mid);
    }
};