class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        ump[0] = 1;
        int sum = 0, ans = 0;
        
        for(auto &it: nums){
            sum += it;
            int ele = sum - k;
            
            if(ump.find(ele) != ump.end())
                ans += ump[ele];
            
            ump[sum]++;
        }
        
        return ans;
    }
};