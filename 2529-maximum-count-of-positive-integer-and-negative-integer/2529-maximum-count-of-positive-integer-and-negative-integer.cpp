class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count = 0,countz = 0;
        for(auto it : nums){
            if(it < 0)
                count++;
            else if(it == 0)
                countz++;
            else
                break;
        }
        
        int pos = nums.size()-count-countz;
        return max(count,pos);
    }
};