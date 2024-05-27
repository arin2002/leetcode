class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        auto solve = [&](int x){
            int it = lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            return x == (n-it);
        };
        

        for(int i = 0; i<=n; i++){
            if(solve(i))
                return i;
        }
        
        return -1;
    }
};