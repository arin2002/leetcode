class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i<n - k + 1; i++){
            
            int maxi = nums[i];
            for(int j = i+1; j<n; j++){
                if(j-i+1>k)
                    break;
                
                if(nums[j-1]+1 != nums[j]){
                    maxi = -1;
                    break;
                }
                
                maxi = nums[j];
            }
            
            ans.push_back(maxi);
        }
        
        return ans;
    }
};