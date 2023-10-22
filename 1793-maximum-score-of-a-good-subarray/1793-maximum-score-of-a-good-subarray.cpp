class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int mini=nums[k], maxi=mini, i=k, j=k;
        while(i>0 || j<nums.size()-1){
            if((i>0 && nums[j+1]<nums[i-1]) || j==nums.size()-1){
                i--;
            }
            else{
                j++;
            }
            mini=min(mini, min(nums[i], nums[j]));
            maxi=max(maxi, mini*(j-i+1));
        }
        return maxi;
    }
};
