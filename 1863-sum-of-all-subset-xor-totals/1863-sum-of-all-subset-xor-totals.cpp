class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        
        function<int(int,int)> solve = [&](int ind, int curr){
            if(ind == n)
                return curr;
            
            int l = solve(ind+1,curr);
            int r = solve(ind+1,curr^nums[ind]);
            
            return l+r;
        };
        
        return solve(0,0);
    }
};