class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        // unordered_set<int> st;
        // vector<int> v(2001);
        bitset<2048> bs;
        
        for(auto &it: nums){
            auto i = bs[1024-it];
            
            if(i)
                ans = max(ans,abs(it));
            
            bs[it+1024] = true;
        }
        
        return ans;
    }
};