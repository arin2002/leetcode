class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i=0,j=0;
            int sum=0;
           for(int i=0;i<nums.size();i++)
           sum+=nums[i];
            int cur=0;
            int ans=INT_MAX;

            while(j<nums.size())
            {
                    cur+=nums[j];
                    while(i<=j && cur>sum-x)
                    {
                        cur-=nums[i];
                        i++;
                    }

                    if(sum-x==cur)
                    {
                        
                        
                        ans=min(ans,n-(j-i+1));
                    }

                    j++;
            }
      

        return ans==INT_MAX?-1:ans;
        
    }
};
