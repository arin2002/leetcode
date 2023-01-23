class Solution {
public:
    
    vector<vector<string>> ans;
    vector<string> temp;
    
    bool check(int row,int col, int n){
        int tempRow = row, tempCol = col;
        
        while(tempRow >= 0 && tempCol >= 0){
            if(temp[tempRow][tempCol] == 'Q')
                return false;
            
            tempRow--;
            tempCol--;
        }
        
        tempCol = col;
        while(tempCol >= 0){
            if(temp[row][tempCol] == 'Q')
                return false;
            
            tempCol--;
        }
        
        while(row<n && col>=0){
            if(temp[row][col] == 'Q')
                return false;
            
            row++;
            col--;
        }
        
        return true;
    }
    
    
    void solve(int col,int n){
        if(col == n){
            ans.push_back(temp);
        }
        
        for(int row = 0; row<n; row++){
            if(check(row,col,n)){
                temp[row][col] = 'Q';
                solve(col+1,n);
                temp[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        temp.resize(n,s);
        solve(0,n);
        
        return ans;
    }
};