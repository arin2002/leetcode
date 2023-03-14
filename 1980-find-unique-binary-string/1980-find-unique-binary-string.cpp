class Solution {
public:
    int n;
    string ans;
    
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].size();
        
        int i = 0;
        for(auto &it : nums){
            ans += it[i++] == '0' ? '1':'0';
        }
        return ans;
    }
};