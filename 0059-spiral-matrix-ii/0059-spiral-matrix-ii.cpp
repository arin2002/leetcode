class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int total = n*n;
        
        int left = 0, right = n-1, top = 0, bottom = n-1, count = 0;
        
        while(count<total){
            for(int i = left; count<total && i <= right; i++){
                ans[top][i] = count+1;
                count++;
            }
            
            top++;
            
            for(int i = top; count<total && i <= bottom; i++){
                ans[i][right] = count+1;
                count++;
            }
            
            right--;
            
            for(int i = right; count<total && i >= left ; i--){
                ans[bottom][i] = count+1;
                count++;
            }
            
            bottom--;
            
            for(int i = bottom; count<total && i >= top ; i--){
                ans[i][left] = count+1;
                count++;
            }
            
            left++;
            
        }
        
        return ans;
    }
};