class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<int> row(n), col(m);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
       for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]){
                    int a = row[i]-1, b = col[j]-1;
                    
                    if(a == 0 && b == 0)
                        ans++;
                }
            }
        } 
        
        return ans;
    }
};