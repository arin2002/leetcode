class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        unordered_map<int,int> ump;
        
        int i = 0, j = nums.size();
        for(auto it : nums){
            ump[it] = i++;
        }
        
        for(i = 0; i<j; i++){
            int val = target-nums[i];
            auto it = ump.find(val);
            
            if(it != ump.end() && i!= it->second){
                return {i,it->second};
            }
        }
        
        return ans;
    }
};