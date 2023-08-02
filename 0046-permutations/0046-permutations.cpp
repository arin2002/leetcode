class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(n);
        
        // syntax is function<return type (operands type) function name = [&]()-> return type)
        function<void()> solve = [&]() -> void{
            if(temp.size() == n){
                ans.push_back(temp);
                return;
            }
            
            for(int i = 0; i<n; i++){
                if(!vis[i]){
                    vis[i] = 1;
                    temp.push_back(nums[i]);
                    solve();
                    temp.pop_back();
                    vis[i] = 0;
                }
            }
        };
        
        solve();
        return ans;
    }
};