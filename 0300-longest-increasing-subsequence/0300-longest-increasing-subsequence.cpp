class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i = 1; i<nums.size(); i++){
            if(temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                //this is bs here now to replace from array
                // as we need only lrngth
                // like [10] is there in temp now we need to add 9
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
            }
        }
        
        return temp.size();
    }
};