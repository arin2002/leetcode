class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0; i<n; i++)
            sort(grid[i].begin(),grid[i].end(),greater<>());
        
        for(int i = 0 ;i <m; i++){
            int curr = 0;
            for(int j = 0; j<n; j++){
                curr = max(curr,grid[j][i]);
            }
            
            ans += curr;
        }
        
        return ans;
    }
};