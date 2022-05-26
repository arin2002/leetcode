class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        int min = INT_MAX,ans = nums[0], x=0;
        for(int i = 0 ; i<n ; i++)
        {
            int temp = abs(nums[i]);
            if(temp<min)
            {
                min = temp;
                ans = nums[i];
            }
            else if(temp == min)
            {
                if(ans<nums[i])
                    ans = nums[i];
            }
        }
        return ans;
    }
};