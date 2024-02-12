class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        
        for(auto &it: nums){
            ump[it]++;
            
            if(ump[it] > n/2){
                return it;
            }
        }
        
        return -1;
    }
};