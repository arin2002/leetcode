class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long p=1;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==0)
               return 0;
           else if(nums[i]<0)
               p*=-1;
       }
        return p;
    }
};
