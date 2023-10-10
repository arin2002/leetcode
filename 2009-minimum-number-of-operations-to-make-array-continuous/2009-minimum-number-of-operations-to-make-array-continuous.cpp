class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=INT_MAX;
        int sz=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> nums2;
        nums2.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums2.push_back(nums[i]);
            }
        }
        int mx_length=1;
        for(int i=0;i<nums2.size();i++){
            int lb=lower_bound(nums2.begin()+i,nums2.end(),nums2[i]+nums.size())-nums2.begin()-i;
            mx_length=max(mx_length,lb);
        }
        return nums.size()-mx_length;
    }
};
