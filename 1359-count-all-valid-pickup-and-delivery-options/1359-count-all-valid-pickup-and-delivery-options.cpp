#define mod 1000000007
class Solution {
public:
    int countOrders(int n) {
        if(n == 1) return 1;
        long long int ans = 1;
        for(int i=2;i<=n;i++){
            int y = 2*i-1;
            ans = ((ans)*((1LL*y*(y+1))/2))%mod;
        }
        return ans;
    }
};
