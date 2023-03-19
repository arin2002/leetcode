class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(), prod = 1;
        vector<int> pre(n),suff(n);
        
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                prod = 1;
                continue;
            }
            
            prod *= nums[i];
            pre[i] = prod;
        }
        
        prod = 1;
        
        int ans = INT_MIN,  flag = 0;
        for(int j = n-1; j >=0 ; j--){
            if(nums[j] == 0){
                flag = 1;
                prod = 1;
                continue;
            }
            prod *= nums[j];
            ans = max(ans,max(prod,pre[j]));
        }
        
        if(flag)
            return max(ans,0);
        
        return ans;
    }
};