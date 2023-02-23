class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        vector<pair<int,int>> vp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0)
                    vp.push_back({i,j});
            }
        }
        
        if(vp.size() == 0 || vp.size() == n*m)
            return;
        
        for(int i = 0; i<vp.size(); i++){
            int row = vp[i].first;
            int col = vp[i].second;
            
            for(int j = 0; j<m; j++){
                matrix[row][j] = 0;
            }
            
            for(int j = 0; j<n; j++){
                matrix[j][col] = 0;
            }
        }
    }
};