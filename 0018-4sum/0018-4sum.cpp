class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){
                
                long long k = (long)target-nums[i]-nums[j];
                int l = j+1, r = n-1;
                
                while(l<r){
                    long long sum = nums[l]+nums[r];
                    
                    if(sum == k){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++; r--;
                        while(l<r && nums[l] == nums[l-1]) l++;
                        while(l<r && nums[r] == nums[r+1]) r--;
                    }
                    else if(sum < k){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                
                while(j+1<n && nums[j] == nums[j+1]) j++;
                while(i+1<n && nums[i] == nums[i+1]) i++;
            }
        }
        
        return ans;
    }
};