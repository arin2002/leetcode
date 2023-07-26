class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        
        for(int i = 0; i<n; i++){
            if(nums[i]&1){
                nums[i] = 1;
            }
            else{
                nums[i] = 0;
            }
        }
        
        unordered_map<int,int> ump;
        ump[0] = 1;
        int sum = 0;
        
        for(int i = 0; i<n; i++){
            sum += nums[i];
            auto it = ump.find(sum-k);
            
            if(it != ump.end())
                ans += it->second;
            
            ump[sum]++;
        }
        
        return ans;
    }
};