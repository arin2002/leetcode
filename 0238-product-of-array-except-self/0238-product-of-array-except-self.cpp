class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<int> pref(n),suff(n), ans(n);
        vector<int> ans(n,1);
        // pref[0] = nums[0]; suff[n-1] = nums[n-1];
        // we are making ans array as prefix
        int prod = 1;
        for(int i = 0; i<n; i++){
            // pref[i] = pref[i-1]*nums[i];
            ans[i] = prod;
            prod *= nums[i];
        }
        
        // now we will do suffix part
        prod = 1;
        for(int i = n-1; i>=0; i--){
            // suff[i] = suff[i+1]*nums[i];
            ans[i] *= prod;
            prod *= nums[i];
        }
        
//         for(int i = 0; i<n; i++){
//             int a = 1, b = 1;
//             if(i-1>=0){
//                 a = pref[i-1];
//             }
            
//             if(i+1<n){
//                 b = suff[i+1];
//             }
            
//             ans[i] = a*b;
//         }
        
        return ans;
    }
};