class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++){
            int l = i+1;
            int r = n-1;
            int target = 0-nums[i];
            
            while(l<r){
                int sum = nums[l] + nums[r];
                
                if(sum == target){
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    ans.push_back(temp);
                    
                    while(l<r && nums[l] == temp[1]) l++;
                    while(l<r && nums[r] == temp[2]) r--;
                }
                
                else if(sum < target)
                    l++;
                else
                    r--;
            }
            
            while (i < n-1 && nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};