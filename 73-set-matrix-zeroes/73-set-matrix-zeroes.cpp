class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        vector<vector<int>> v(n,vector<int>(m,1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int x = 0; x<n; x++){
                        v[x][j] = 0;
                    }
                    
                    for(int x = 0; x<m; x++){
                        v[i][x] = 0;
                    }
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(v[i][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};