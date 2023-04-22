class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](auto a, auto b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans;
        
        if(nums[0] == 0)
            return "0";
        
        for(auto &it: nums){
            ans += to_string(it);
        }
        
        return ans;
    }
};