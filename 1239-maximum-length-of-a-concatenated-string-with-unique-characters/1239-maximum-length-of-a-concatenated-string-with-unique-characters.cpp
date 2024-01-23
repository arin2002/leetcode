class Solution {
public:
    int maxLength(vector<string>& nums) {
        int n = nums.size();
        int ans = 0;
        string t;
        
        function<void(int, string)> solve = [&](int ind, string t){
            if(ind == n){
                // unordered_set<char> st;
                vector<char> st(26);
                
                for(auto &it: t){
                    
                    st[it-'a']++;
                    
                    if(st[it-'a'] > 1)
                        return;
                }
                
                ans = max(ans,(int)t.size());
                return;
            }
            
            solve(ind+1,t+nums[ind]);
            solve(ind+1,t);
        };
        
        solve(0,t);
        return ans;
    }
};