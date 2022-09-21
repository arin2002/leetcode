class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        
        int n = nums.size();
        int m = queries.size();
        
        int sum = 0;
        for(int i = 0;i<n; i++){
            if(nums[i]%2 == 0){
                sum += nums[i];
            }
        }
        
        for(int i = 0; i<m; i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            
            if(nums[ind] % 2 == 0)
                sum -= nums[ind];
            
            nums[ind] += val;
            
            if(nums[ind]%2 == 0)
                sum+= nums[ind];
            
            ans.push_back(sum);
        }
        
        
        return ans;
    }
};