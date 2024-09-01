class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size(), ind = 0;
        vector<vector<int>> ans(m,vector<int>(n));
        
        if(!(size == m*n))
            return vector<vector<int>>();
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans[i][j] = original[ind++];
            }
        }
        
        return ans;
    }
};