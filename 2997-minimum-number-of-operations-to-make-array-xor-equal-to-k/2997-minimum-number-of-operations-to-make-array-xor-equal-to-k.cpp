class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> bits(32);
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < 32;j++){
                if(nums[i] & (1 << j)){
                    bits[j]++;
                }
            }
        }
        int count = 0;
        for(int i = 0;i < 32;i++){
            if(k & (1 << i)){
                if(bits[i] % 2 == 0){
                    count++;
                }
            }else{
                if(bits[i] % 2){
                    count++;
                }
            }
        }
        return count;
    }
};
