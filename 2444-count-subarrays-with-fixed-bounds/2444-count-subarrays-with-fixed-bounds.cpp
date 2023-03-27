class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minKpos = -1, maxKpos = -1, culprit = -1; 
        
        long long ans = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]>maxK || nums[i]<minK){
                // reset pointer as got max/min
                culprit = i;
                minKpos = -1;
                maxKpos = -1;
                continue;
            }
            
            if(nums[i] == maxK)
                maxKpos = i;
            
            if(nums[i] == minK)
                minKpos = i;
            
            // this is the main forumla one should come with
            ans += max(0,min(maxKpos,minKpos)-culprit);
        }
        return ans;
    }
};