class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // keep high at n-2
        int low = 0, high = nums.size()-1;
        
        // for left half
        // 1st instance = even
        // 2nd instanc = odd
        
        if(high == 0)
            return nums[0];
        
        while(low<=high){
            int mid = (low+high)/2;
            
            // mid^1 trick used if at even ind mid it will give prev ind like at 4 then 3 aa jayega
            // if odd then mid+1 ho jayega
            if(nums[mid] == nums[mid^1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return nums[low];
    }
};