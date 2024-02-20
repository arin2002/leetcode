class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        int flag = 1;
        
        for(auto &it: nums){
            sum += it;
            
            if(it == 0)
                flag = 0;
        }
        
        if(flag)
            return 0;
        
        return abs(sum-((n*(n+1))/2));
    }
};