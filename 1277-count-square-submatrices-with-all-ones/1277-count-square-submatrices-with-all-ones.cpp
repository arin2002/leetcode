class Solution {
    bool check(vector<vector<int>>& matrix,int row,int col,int it){
        for(int i=0;i<it;i++){
            for(int j=0;j<it;j++){
                if(matrix[row+i][col+j]!=1){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int small=min(matrix.size(),matrix[0].size());
        for(int i=1;i<=small;i++){
            for(int j=0;j<matrix.size()-i+1;j++){
                for(int k=0;k<matrix[0].size()-i+1;k++){
                    if(check(matrix,j,k,i)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};