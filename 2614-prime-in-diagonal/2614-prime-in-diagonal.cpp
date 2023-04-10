class Solution {
public:
    
    bool check(int n){
        if(n == 1)
            return false;
        
        for(int i = 2; i*i<= n; i++){
            if(n%i == 0)
                return false;
        }
        
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        
        int n = nums.size(), ans = 0;
        
        for(int i = 0; i<n; i++){
            if(check(nums[i][i])){
                ans = max(ans,nums[i][i]);
            }
            
            if(check(nums[i][n-1-i]))
                ans = max(ans,nums[i][n-1-i]);
        }
        
        return ans;
    }
};