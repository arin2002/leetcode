class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1;
        sort(nums.begin(),nums.end());
        long long sum=nums[0]+nums[1];
        for(int i=2;i<nums.size();i++){
            if(nums[i]<sum){
                ans=sum+nums[i];
            }
            sum+=nums[i];
        }
        return ans;
    }
};
