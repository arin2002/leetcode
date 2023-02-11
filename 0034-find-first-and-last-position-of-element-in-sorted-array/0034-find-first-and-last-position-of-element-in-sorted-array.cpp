class Solution {
public:
    
    vector<int> ans;
    
    void firstocc(int k, vector<int> &nums){
        int i = 0, j = nums.size()-1, mid = 0;
        
        while(i<=j){
            mid = i + (j-i)/2;
            
            if(nums[mid] == k){
                ans[0] = mid;
                j = mid-1;
            }
            else if(nums[mid]<k){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
    }
    
    void lastocc(int k, vector<int> &nums){
        int i = 0, j = nums.size()-1, mid = 0;
        
        while(i<=j){
            mid = i + (j-i)/2;
            
            if(nums[mid] == k){
                ans[1] = mid;
                i = mid+1;
            }
            else if(nums[mid]<k){
                i = mid+1;
            }
            else{
                
                j = mid-1;
            }
        }
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        ans.resize(2,-1);
        firstocc(target,nums);
        lastocc(target,nums);
        
        return ans;
    }
};