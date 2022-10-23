class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        
        long long n = abs(x);
        while(n>0){
            ans = ans*10 + n%10;
            n/=10;
        }
        
        if(ans>= INT_MAX)
            return 0;
        
        if(x<0)
            ans*=-1;
        
        return ans;
    }
};