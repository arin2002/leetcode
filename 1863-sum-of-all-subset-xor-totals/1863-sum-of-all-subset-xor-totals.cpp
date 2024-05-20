class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> t;
        
        function<void(int)> solve = [&](int ind){
            if(ind == n){
                int m = t.size();
                
                if(m == 0)
                    return;
                
                int temp = t[0];
                
                for(int i = 1; i<m; i++){
                    temp ^= t[i];
                }
                
                ans  += temp;
                return;
            }
            
            t.push_back(nums[ind]);
            solve(ind+1);
            t.pop_back();
            solve(ind+1);            
        };
        
        solve(0);
        return ans;
    }
};