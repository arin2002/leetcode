class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxvalue=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(maxvalue<nums[i])
            {
                maxvalue=nums[i];
            }
        }
        int maxcount=1;
        int tempcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxvalue)
            {
                tempcount++;
            }
            else
            {
                maxcount=max(maxcount,tempcount);
                tempcount=0;
            }
        }
        maxcount=max(maxcount,tempcount);

        return maxcount;
    }
};
