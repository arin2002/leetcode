class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // int maxi = 0;
        // for(auto &it: nums){
        //     it *= it;
        //     maxi = max(it,maxi);
        // }
        
        // sort(nums.begin(),nums.end());
//         vector<int> v(maxi+1);
        
//         for(auto &it: nums){
//             v[it]++;
//         }
        
//         int j = 0;
//         for(int i = 0; i<=maxi; i++){
//             while(v[i]-->0){
//                 nums[j++] = i;
//             }
//         }
        int left = 0, n = nums.size(), right = n-1, ind = n-1;
        vector<int> ans(n);
        
        while(left<=right){
            int l = nums[left]*nums[left];
            int r = nums[right]*nums[right];
            
            if(l<=r){
                right--;
                ans[ind--] = r;
            }
            else{
                ans[ind--] = l;
                left++;
            }
        }
        
        return ans;
    }
};