class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // line sweep algo
        int ans = 0;
        map<int,int> ump;
        for(auto &it: nums){
            ump[it-k]++;
            ump[it+k+1]--;
        }
        
        int len = 0;
        for(auto &it: ump){
            len += it.second;
            ans = max(ans,len);
        }
        
        return ans;
    }
};