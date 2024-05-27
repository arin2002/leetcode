class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        auto solve = [&](int x){
            int it = nums.end()-lower_bound(nums.begin(),nums.end(),x);
            return x == it;
        };
        

        for(int i = 0; i<=n; i++){
            if(solve(i))
                return i;
        }
        
        return -1;
    }
};