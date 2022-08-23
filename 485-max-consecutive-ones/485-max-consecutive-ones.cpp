class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        
        int count = 0;
        
        for(int i = 0; i<n; i++)
        {
            int temp = 0;
            
            // if(i == n-1){
            //     if(nums[i]==1)
            //         temp = 1;
            // }
            // else{
            while(nums[i] == 1){
                i++;
                temp++;
                
                if(i == n)
                    break;
            }
            // }
            count = max(count,temp);
        }
        
        return count;
    }
};