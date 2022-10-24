class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int temp = nums[i];
            
            for(int j = i; j<n; j++){
                temp = gcd(temp,nums[j]);

                if(temp == k)
                    ans++;
                
                if(temp<k)
                    break;
            }
        }
        
        return ans;
    }
};