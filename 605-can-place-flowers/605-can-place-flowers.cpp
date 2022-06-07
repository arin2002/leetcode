class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int m) {
        int n = nums.size();
        
        if(m==0)
            return true;
        
        if(n==1 && nums[0]==0 && n==1) return true;

        for(int i = 0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                if(i==0){
                    if(nums[i+1] == 0){
                    m--;
                    nums[i] = 1;
                    }
                }
                else if(i == n-1){
                    if(nums[i-1] == 0){
                    m--;
                    nums[i] =1;
                    }
                }
                else {
                    if(nums[i-1] == 0 && nums[i+1] == 0){
                        m--; nums[i] =1 ;
                    }
                }   
            }
        }
        cout<<m;
        if(m<=0)
            return true;
        
        return false;
    }
};