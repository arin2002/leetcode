class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> ump;
        
        int ans = 0;
        for(auto it:nums)
            ump[it]++;
        
        for(auto it: ump){
            if(it.second == 1)
                ans += it.first;
        }
        
        return ans;
    }
};