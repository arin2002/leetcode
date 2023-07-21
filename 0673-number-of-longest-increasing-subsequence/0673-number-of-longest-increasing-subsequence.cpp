class Solution {
public:        
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> last(n,1), count(n,1);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j]<nums[i]){
                    if(last[j]+1 > last[i]){
                        last[i] = last[j]+1;
                        count[i] = 0;
                    }
                    
                    if(last[i] == last[j]+1){
                        count[i] += count[j];
                    }
                }
            }
        }
        
        int maxlen = *max_element(last.begin(),last.end());
        
        for(int i = 0; i<n; i++){
            if(maxlen == last[i])
                ans += count[i];
        }
        
        return ans;
    }
};