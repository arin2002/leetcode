class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(n);
        
        // syntax is function<return type (operands type) function name = [&]()-> return type)
        function<void(int)> solve = [&](int ind) -> void{
            if(temp.size() == n){
                ans.push_back(temp);
                return;
            }
            
            for(int i = 0; i<n; i++){
                if(!vis[i]){
                    vis[i] = 1;
                    temp.push_back(nums[i]);
                    solve(i+1);
                    temp.pop_back();
                    vis[i] = 0;
                }
            }
        };
        
        solve(0);
        return ans;
    }
};