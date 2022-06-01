class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> v;
        int n = nums.size(),sum = 0;
        for(int i = 0 ; i<n;i++)
            v.push_back(sum+=nums[i]);
        
        return v;
    }
};