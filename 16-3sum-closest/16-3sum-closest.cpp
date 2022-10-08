class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int closet = nums[0]+nums[1]+nums[2];
        
        for(int i = 0; i<n-2; i++){
            int l = i+1, r = n-1;
            
            while(l<r){
                int temp = nums[i]+nums[l]+nums[r];
                
                
                if(temp == target)
                    return target;
                
                else if(abs(temp-target) < abs(closet-target))
                    closet = temp;
                
                if(temp<target)
                    l++;
                else
                    r--;
            }
        }
        
        return closet;
    }
};