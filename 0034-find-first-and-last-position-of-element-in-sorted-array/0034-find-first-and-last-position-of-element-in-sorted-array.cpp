class Solution {
public:
    
    int firstOcc(vector<int> &nums, int target){
        int ind = -1, low = 0, high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target){
                ind = mid;
                high = mid - 1;
            }
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return ind;
    }
    
    int lastOcc(vector<int> &nums, int target){
        int ind = -1, low = 0, high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target){
                ind = mid;
                low = mid + 1;
            }
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return ind;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        ans.push_back(firstOcc(nums,target));
        ans.push_back(lastOcc(nums,target));
        
        return ans;
    }
};