class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 1;
        int n = nums.size();
        int count=1,i=0;
        
        for(; i<n;i++)
        {
            sum += nums[i];         
            if(sum <=0)
            {
                sum = ++count;
                i = -1;
            }
        }
        
        return count;
    }
};