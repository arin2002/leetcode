class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //vector<int> v;
        //int n = nums.size();
        for(int i = 1 ; i<nums.size();i++)
            nums[i] += nums[i-1];
        return nums;
    }
};