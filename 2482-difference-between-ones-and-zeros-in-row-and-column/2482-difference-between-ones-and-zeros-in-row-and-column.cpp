class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> oneRow(n,0), zeroRow(n,0), oneCol(m,0),zeroCol(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    zeroRow[i]++;
                    zeroCol[j]++;
                }
                else{
                    oneRow[i]++;
                    oneCol[j]++;
                }
            }
        }
        vector<vector<int>> diff(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<oneRow[i]<<" "<<oneCol[j]<<" "<<zeroRow[i]<<" "<<zeroCol[j]<<endl;
                diff[i][j]=oneRow[i]+oneCol[j]-zeroRow[i]-zeroCol[j];
            }
        }
        return diff;
    }
};
