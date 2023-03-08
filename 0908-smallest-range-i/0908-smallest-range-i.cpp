class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxi = INT_MIN, mini = INT_MAX;
        
        for(auto &it : nums){
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
        
        if(maxi == mini)
            return 0;
        
        int ans = (maxi-k)-(mini+k);
        
        return max(ans,0);
    }
};