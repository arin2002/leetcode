class Solution {
public:

    int findpivot(int s, int e,vector<int>&nums){
        if(s>e)return 0;
        int mid=(s+e)/2;
        if(s==e)return mid;
        if(nums[mid]<nums[e])return findpivot(s,mid,nums);
        return findpivot(mid+1,e,nums);
    }

    int bs(int s,int e,vector<int>&nums,int tgt){
        if(s>e)return -1;
        int mid=(s+e)/2;
        if(s==e&&nums[s]==tgt)return mid;
        if(nums[mid]==tgt)return mid;
        else if(nums[mid]>tgt)return bs(s,mid-1,nums,tgt);
        return bs(mid+1,e,nums,tgt);
    }

    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int pivot=findpivot(s,e,nums);
        int a=bs(s,pivot-1,nums,target);
        if(a!=-1)return a;
        return bs(pivot,e,nums,target);
    }
    
};
