class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n<0){
            n = abs(n);
            x = 1/x;
        }
        
        while(n>0){
            if(n&1){
                res *= x;
                n--;
            }
            else{
                x = x*x;
                n >>= 1;
            }
        }
        
        return res;
    }
};