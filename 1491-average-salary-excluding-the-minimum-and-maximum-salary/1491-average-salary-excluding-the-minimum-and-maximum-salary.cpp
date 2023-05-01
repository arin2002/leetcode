class Solution {
public:
    double average(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        
        double total = 0, n = 0;
        for(auto &it: nums){
            if(it == mini || it == maxi)
                continue;
            
            total+=it;
            n++;
        }
        
        total /= n;
        return total;
    }
};