class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3)
            return false;
        
        //keep track of smallest in this
        
        int i = INT_MAX, j = INT_MAX;
        for(auto it: nums){
            if(it<=i)
                i = it;
            
            else if(it<=j)
                j = it;
            else
                return true;
   
        }
        return false;
    }
};