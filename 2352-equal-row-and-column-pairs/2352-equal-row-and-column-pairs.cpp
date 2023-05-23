class Solution {
public:
    
    bool check(int i,vector<int> nums, vector<vector<int>>& grid){
        int k = 0;
        for(int j = 0; j<grid.size(); j++){
            if(grid[j][i] != nums[k++])
                return false;
        }
        
        return true;
    }
    
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        
        for(auto &it: grid){
            for(int i = 0; i<n; i++){
                if(check(i,it,grid))
                    ans++;
            }
        }
        
        return ans;
    }
};