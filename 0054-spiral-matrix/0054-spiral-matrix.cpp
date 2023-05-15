class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int total = n*m;
        
        int top = 0, bottom = n-1, left = 0, right = m-1, count = 0;
        
        while(count <total){
            for(int i = left; count<total && i<=right; i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            
            for(int i = top; count<total && i<=bottom; i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            
            right--;
            
            for(int i = right; count<total && i>=left; i--){
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            
            bottom--;
            
            for(int i = bottom; count<total && i>=top; i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
            cout<<count<<" ";
        }
        
        return ans;
    }
};