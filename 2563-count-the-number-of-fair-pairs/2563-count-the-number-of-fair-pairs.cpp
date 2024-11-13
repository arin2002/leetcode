class Solution {
public:
    
//     long long bs(vector<int>& nums, int ind,int lower, int upper){
//         int i = 0, j = nums.size()-1;
        
//         while(i<=j){
//             long long mid = i + (j-i)/2;
            
//             long long temp = nums[ind] + nums[mid];
            
//             if(temp >= lower && temp <= upper){
//                 return mid - i;
//             }
//             else if(temp> upper)
//                 j = mid-1;
            
//             else
//                 i = mid + 1;
//         }
        
//         return 0;
//     }
    
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {      
        
        
        if(lower>upper)
            return 0;
        
        sort(nums.begin(),nums.end());
                
        long long count = 0;
        for(int i =0; i<nums.size(); i++){
            int l = lower-nums[i], r = upper - nums[i];
            
            int j = lower_bound(nums.begin()+i+1,nums.end(),l)-nums.begin();
            int k = upper_bound(nums.begin()+i+1,nums.end(),r)-nums.begin()-1;
            
            // valid range
            if(j<=k)
                count += k-j+1;
        }
        
//         int l = 0, r = nums.size()-1;
        
//         while(l<r){
//             long long temp = nums[l] + nums[r];
            
//             if(temp >= lower && temp <= upper){
//                 count ++;
//                 r--;
//             }
//             else if(temp > upper)
//                 r--;
//             else
//                 l++;
//         }
        
        return count;
    }
};