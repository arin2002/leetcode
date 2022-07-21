class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int i = 0, j = n-1;
        
        int mini = 0;
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;
            
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                mini = mid;
                break;
            }
            
            else if(nums[mid] < nums[j])
                j = mid -1;
            else
                i = mid+1;
        }
        
        i = 0;
        j = mini-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        
        i = mini; j = n-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        return -1;
    }
};