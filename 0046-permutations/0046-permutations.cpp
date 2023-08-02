class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(n);
        
        // syntax is function<return type (operands type) function name = [&]()-> return type)
        function<void(int)> solve = [&](int ind) -> void{
            if(ind == n){
                ans.push_back(nums);
                return;
            }
            
            for(int i = ind; i<n; i++){
                swap(nums[i],nums[ind]);
                solve(ind+1);
                swap(nums[i],nums[ind]);
            }
        };
        
        solve(0);
        return ans;
    }
};