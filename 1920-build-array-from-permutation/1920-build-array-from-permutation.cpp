class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 0 ; i< n ; i++)
        {
            int j = nums[i];
            int x = nums[j];
            v.push_back(x);
        }
        
        return v;
    }
};