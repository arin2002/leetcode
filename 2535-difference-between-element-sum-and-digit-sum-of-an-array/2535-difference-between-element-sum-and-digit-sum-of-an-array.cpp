class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0, total = 0;
        
        for(auto &it: nums){
            sum += it;
            
            while(it){
                total += it%10;
                it /=10;
            }
        }
        
        return abs(total-sum);
    }
};