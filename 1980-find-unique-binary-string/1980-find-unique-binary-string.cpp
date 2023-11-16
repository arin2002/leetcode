class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(),nums.end());
        int n = nums[0].size();
        string ans;
        
        function<void(string)> solve = [&](string s){
            if(s.size() == n){
                if(st.find(s) == st.end()){
                    ans = s;
                    return;
                }
                return;
            }
            
            solve(s+'0');
            solve(s+'1');
            
        };
        
        solve("");
        return ans;
    }
};