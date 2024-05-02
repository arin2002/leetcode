class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> st(nums.begin(),nums.end());
        
        for(auto &it: nums){
            auto i = st.find(it*(-1));
            
            if(i != st.end())
                ans = max(ans,it);
            
        }
        
        return ans;
    }
};