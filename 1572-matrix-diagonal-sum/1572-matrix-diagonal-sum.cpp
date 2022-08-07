class Solution {
public:
    int diagonalSum(vector<vector<int>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0, ans1 = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == j ){
                    ans+=mat[i][j];
                    mat[i][j] = 0;
                }
                if ((i + j) == (n - 1))
                    ans1 += mat[i][j];
            }
        }
        
        return ans+ans1;
    }
};