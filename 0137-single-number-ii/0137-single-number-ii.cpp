class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto &it: nums){
            ump[it]++;
        }
        
        for(auto [a,b] : ump){
            if(b == 1)
                return a;
        }
        
        return -1;
    }
};