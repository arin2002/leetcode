class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int n = a.size(), m = a[0].size();
        int left = 0, up = 0;
        int right = m-1, down = n-1;
        int count = 0, total = m*n;
        
        while(count<total){
            for(int i = left; i<=right && count<total; i++){
                ans.push_back(a[up][i]);
                count++;
            }
            up++;
            
            for(int i = up; i<=down && count<total; i++){
                ans.push_back(a[i][right]);
                count++;
            }
            right--;
            
            for(int i = right; i>=left && count<total; i--){
                ans.push_back(a[down][i]);
                count++;
            }
            down--;
            
            for(int i = down; i>=up && count<total; i--){
                ans.push_back(a[i][left]);
                count++;
            }
            left++;
        }
        
        return ans;
        
    }
};