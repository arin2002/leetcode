class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, start = 0;
        
        // if(find(nums.begin(),nums.end(),0) == nums.end())
        //     return n-1;
        
        int countZ = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                countZ++;
            }
            
            if(countZ > 1){
                while(start<n && nums[start] == 1) start++;
                start++; countZ--;
            }
            
            // if(countZ){
            //     ans = max(ans,i-start);
            // }
            // else{
            //     ans = max(ans,i-start+1);
            // }
            ans = max(ans,i-start);
        }
        
        return ans;
    }
};