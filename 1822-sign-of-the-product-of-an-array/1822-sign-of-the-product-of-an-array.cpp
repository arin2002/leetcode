class Solution {
public:
    int arraySign(vector<int>& nums) {
        // speedup code with disable sync c and relation cin & cout
        ios::sync_with_stdio(false); cin.tie(nullptr);

        int neg = 1;
        for(const int& num : nums){
            // if num is negative change neg(sign) to reverse
            if(num < 0)
                neg *= -1;
            // if there is a zero value, the product must be zero
            else if(num == 0)
                return 0;
        }
        return neg;
    }
};