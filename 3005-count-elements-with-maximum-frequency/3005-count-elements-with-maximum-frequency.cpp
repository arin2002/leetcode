class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101);
        int maxi = 0, ans = 0;
        
        for(auto &it: nums){
            maxi = max(++v[it],maxi);
        }
        
        for(auto &it: v){
            if(maxi == it)
                ans++;
        }
        
        return ans*maxi;
    }
};