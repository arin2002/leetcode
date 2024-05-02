class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> st;
        
        for(auto &it: nums){
            auto i = st.find(it*(-1));
            
            if(i != st.end())
                ans = max(ans,abs(it));
            
            st.insert(it);
        }
        
        return ans;
    }
};