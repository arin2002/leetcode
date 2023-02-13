class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        
        for(auto it : nums){
            if(it == 0)
                count0++;
            
            else if(it == 1)
                count1++;
            else
                count2++;
        }
        
        
        for(auto &it: nums){
            if(count0){
                it = 0;
                count0--;
            }
            else if(count1){
                it = 1;
                count1--;
            }
            else{
                it = 2;
            }
        }
    }
};