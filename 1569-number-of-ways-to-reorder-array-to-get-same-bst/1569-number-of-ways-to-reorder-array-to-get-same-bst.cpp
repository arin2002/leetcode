class Solution {
public:
    
    typedef long long ll;
    ll mod = 1e9+7;
    vector<vector<ll>> pascal;
    
    int solve(vector<int>& nums){
        int n = nums.size();
        
        if(n < 3)
            return 1;
        
        ll root = nums[0];
        vector<int> left,right;
        for(int i = 1; i<n; i++){
            if(nums[i]>root){
                right.push_back(nums[i]);
            }
            else{
                left.push_back(nums[i]);
            }
        }
        
        // find now for these part arrangment
        // realtive ordeting is done same
        ll x = solve(left);
        ll y = solve(right);
        
        // for current
        ll z = pascal[n-1][left.size()];
        return (x%mod*y%mod*z%mod)%mod;
    }
    
    int numOfWays(vector<int>& nums) {
        // maths questions can say
        int n = nums.size();
        
        pascal.resize(n+1);
        
        for(int i = 0; i<n; i++){
            pascal[i] = vector<ll>(i+1,1);
            for(int j = 1; j<i; j++){
                pascal[i][j] = (pascal[i-1][j]%mod+pascal[i-1][j-1]%mod)%mod; 
            }
        }
        
        return solve(nums)-1;
    }
};