class Solution {
public:
    int minSwaps(vector<int>& nums) {
      int count_one=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]==1){
            count_one++;
        }
        nums.push_back(nums[i]);
      }
     int maxans=0;
     for(int i=0;i<count_one;i++){
        if(nums[i]==0){
            maxans++;
        }
     }
     int ans=maxans;
     int j=0;
     for(int i=count_one;i<nums.size();i++){
        if(nums[j]==0)maxans--;
        if(nums[i]==0)maxans++;
        j++;
        ans=min(ans,maxans);
     }
     return ans;
    }
};
