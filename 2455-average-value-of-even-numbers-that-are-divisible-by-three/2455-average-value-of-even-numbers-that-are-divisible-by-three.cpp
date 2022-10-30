class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ans = 0, n = 0;
        
        for(auto it:nums){
            if(it%6 == 0){
                n++;
                ans+=it;
            }
        }
        
        if(ans == 0)
            return 0;

        return ans/n;
    }
};