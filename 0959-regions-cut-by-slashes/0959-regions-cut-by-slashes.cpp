class Solution {
public:
    void dfs(vector<vector<int>>& binGrid, int i, int j){
        //Step-3: Checking for connected components
        if(i<0 || i>=binGrid.size() || j<0 || j>=binGrid.size()) return;
        if(binGrid[i][j]!=0) return;

        binGrid[i][j]= 2;
        dfs(binGrid, i-1, j);
        dfs(binGrid, i, j+1);
        dfs(binGrid, i+1, j);
        dfs(binGrid, i, j-1);
    }
    int regionsBySlashes(vector<string>& grid) {
        //Converting all symbols present into 3x3 grids
        int n= grid.size();
        int cnt=0;

        //Step-1: Creating a new binary grid where each symbol is represented by a 3x3 grid
        int size= n*3;
        vector<vector<int>> binGrid(size, vector<int> (size, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    binGrid[i*3][j*3+2]= 1;
                    binGrid[i*3+1][j*3+1]= 1;
                    binGrid[i*3+2][j*3]= 1;
                }
                else if(grid[i][j]=='\\'){
                    binGrid[i*3][j*3]= 1;
                    binGrid[i*3+1][j*3+1]= 1;
                    binGrid[i*3+2][j*3+2]= 1;
                }
            }
        }
        //Step-2: If we encounter a 0 we will send it for dfs call to check its connected components and increase the count(i.e. region) by 1
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(binGrid[i][j]==0){
                    dfs(binGrid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
