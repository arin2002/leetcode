class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        
        int n = nums.size();
        int m = nums[0].size();
        
        int i = 0, j = m*n-1;
    
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            int val = nums[mid/m][mid%m];
            
            if(val == target)
                return true;
            
            else if(val < target){
                i = mid +1;
            }
            else{
                j = mid-1;
            }
        }
        
        return false;
    }
};