class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        
        // if(n == 1 || k == 1)
        //     return 0;
        
        int mini = INT_MAX;
        sort(nums.begin(),nums.end());
        
        int j = 0;
        for(int i = k-1; i<nums.size(); i++){
            mini = min(mini,nums[i]-nums[j++]);
        }
        
        return mini;
    }
};