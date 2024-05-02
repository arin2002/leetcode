class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        // unordered_set<int> st;
        vector<bool> v(2001);
        // bitset<2048> bs;
        // int arr[2001] = {0};
        
        for(auto &it: nums){
            auto i = v[1000-it];
            
            if(i)
                ans = max(ans,abs(it));
            
            v[it+1000] = 1;
        }
        
        return ans;
    }
};