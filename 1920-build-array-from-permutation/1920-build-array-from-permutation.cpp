class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 0 ; i< n ; i++)
        {
            int x = nums[nums[i]];
            v.push_back(x);
        }
        
        return v;
    }
};