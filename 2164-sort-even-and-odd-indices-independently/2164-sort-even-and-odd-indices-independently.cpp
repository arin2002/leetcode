class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int gap = 2;
        for(int i=gap; i<nums.size(); i+=2)             //Shell Sort on even indexes
        {
            int temp = nums[i];
            int j = i;
            
            while(j - gap >=0 && nums[j-gap] > temp)
            {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = temp;
        }
        
        for(int i=3; i<nums.size(); i+=2)          //Shell Sort on odd indexes
        {
            int temp = nums[i];
            int j = i;
            
            while(j - gap >=0 && nums[j-gap] < temp)
            {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = temp;
        }
        
        return nums;
    }
};
