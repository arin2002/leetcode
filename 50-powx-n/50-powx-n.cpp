class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long n1 = n;
        if(n1<0) n1*=-1;
        
        while(n1>0){
            if(n1%2==1){
                ans = (ans * x );
                n1--;
            }
            x*=x;
            n1/=2;
        }
        if(n>=0)
        return ans;
        else
            return (double)1/ans;
    }
};