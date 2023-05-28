class Solution {
public:
    long long ans = -1e12;
    
    long long maxStrength(vector<int>& nums) {
        long long zero = 0, posCount = 0, negCount = 0, largestN = -1021;
        long long n = nums.size(), prod = 1;
        
        if(n == 1)
            return nums[0];
        
        for(int i = 0; i<n; i++){
            if(nums[i])
                prod *= (long long)nums[i];
            
            if(nums[i]>0)
                posCount++;
            else if(nums[i]<0){
                negCount++;
                largestN = max((long)largestN,(long)nums[i]);
            }
            else
                zero = 1;
        }
        
        if(posCount == 0 && negCount == 0)
            return 0;
        
        if(zero == 1 && negCount == 1 && posCount == 0)
            return 0;
        
        if(negCount%2 == 0)
            return prod;
        
        if(negCount == 0)
            return prod;
        
        return prod/largestN;
    }
};