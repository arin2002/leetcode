class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       int l=0,r=0,ans=0;
       sort(nums.begin(),nums.end());
       long long sum=nums[0];
        while(r<nums.size()){
            if(1LL*(r-l+1)*nums[r]<=k+sum){
                ans=max(ans,r-l+1);
                r++;
                if(r<nums.size())sum+=nums[r];
            }
            else{
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};
