class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> v;
        vector<int> temp;
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(r*c != n*m)
            return mat;
        
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<m ;j++)
                temp.push_back(mat[i][j]);
        }
        
        int k = 0;
        for(int i =0; i<r; i++)
        {
            vector<int> a;
            for(int j = 0; j<c; j++){
                a.push_back(temp[k++]);
            }
            v.push_back(a);
        }
        
        return v;
    }
};
