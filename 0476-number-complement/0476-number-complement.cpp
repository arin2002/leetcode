class Solution {
public:
    int findComplement(int num) {
        int mask = 0, ans = ~num;
        
        while(num){
            mask <<= 1;
            //last bit mai 0 aata rahega
            mask |= 1;
            
            num >>= 1;
        }
        
        ans &= mask;
        
        return ans;
    }
};