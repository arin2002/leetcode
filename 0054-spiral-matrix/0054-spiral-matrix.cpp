class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        
        int startRow = 0, endRow = n-1;
        int startCol = 0, endCol = m-1;
        
        int total = n*m, count = 0;
        
        while(count<total){
            
            // starting row
            for(int i = startCol; i <= endCol && count<total; i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            
            startRow++;
            
            // ending col
            for(int i = startRow; i <= endRow && count<total; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            
            endCol--;
            
            // ending row
            for(int i = endCol; i >= startCol && count<total; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            
            endRow--;
            
            //print start col
            for(int i = endRow; i >= startRow && count<total; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            
            startCol++;
        }
        
        return ans;
    }
};