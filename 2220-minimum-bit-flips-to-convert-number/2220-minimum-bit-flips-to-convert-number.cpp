class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start ^ goal, ans = 0;
        
        while(xorr){
            int bit = xorr&1;
            
            if(bit){
                ans++;
            }
            
            xorr>>=1;
        }
        
        return ans;
    }
};