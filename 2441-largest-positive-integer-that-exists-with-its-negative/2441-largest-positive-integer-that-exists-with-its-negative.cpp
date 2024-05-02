class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        // unordered_set<int> st;
        vector<int> v(2001);
        
        for(auto &it: nums){
            auto i = v[1000-it];
            
            if(i > 0)
                ans = max(ans,abs(it));
            
            v[it+1000]++;
        }
        
        return ans;
    }
};