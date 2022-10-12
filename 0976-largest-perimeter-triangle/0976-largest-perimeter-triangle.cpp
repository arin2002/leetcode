class Solution {
public:
    
    bool check(int a, int b, int c){
        if(!((a+b)>c && (b+c)>a && (c+a)>b))
            return false;
        
        return true;
    }
    
    
    int largestPerimeter(vector<int>& nums) {
        int a  = 0, b = 0, c = 0;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i = n-1; i>=2; i--){
            if(check(nums[i],nums[i-1],nums[i-2])){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        
        return 0;
    }
};