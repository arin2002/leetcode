class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        
        for(int i = 1; i<n; i++){
            int two = dp[a]*2;
            int three = dp[b]*3;
            int five = dp[c]*5;
            
            int t = min(two,min(three,five));
            
            if(t == two){
                dp[i] = two;
                a++;
            }
            if(t == three){
                dp[i] = three;
                b++;
            }
            
            if(t == five){
                dp[i] = five;
                c++;
            }
        }
        
        return dp[n-1];
    }
};