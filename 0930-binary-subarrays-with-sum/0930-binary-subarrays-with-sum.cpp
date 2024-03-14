class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> ump;
        int sum = 0, ans = 0;
        ump[0] = 1;
        
        for(auto &it: nums){
            sum += it;
            
            if(ump.find(sum-goal) != ump.end()){
                ans += ump[sum-goal];
            }
            
            ump[sum]++;
        }
        
        return ans;
    }
};