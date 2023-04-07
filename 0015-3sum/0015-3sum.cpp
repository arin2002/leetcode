class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0; i<n-2; i++){
            // imp point ha  ye aagr aaise karoge pair nhi aayenge kahi
            
//             if(nums[i] == nums[i+1])
//                 continue;
            
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            int sum = -nums[i];
            int l = i+1, r = n-1;
            
            while(l<r){
                int temp = nums[l] + nums[r];
                
                if(sum == temp){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    // can have more pairs check them
                    int a = nums[l], b = nums[r];
                    // for skipping
                    while(l<r && nums[l] == a) l++;
                    while(l<r && nums[r] == b) r--;
                }    
                else if(temp < sum){
                    l++;
                }
                
                else
                    r--;
            }
        }
        
        return ans;
    }
}; 