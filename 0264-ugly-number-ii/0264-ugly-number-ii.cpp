class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        
        dp[0] = 1;
        
        int a = 0, b = 0, c = 0;
        
        for(int i = 1; i<n; i++){
            int two = 2*dp[a];
            int three = 3*dp[b];
            int five = 5*dp[c];
            
            dp[i] = min(two,min(three,five));
            // cout<<two<<" "<<three<<" "<<five<<" "<<dp[i]<<endl;
            
            if(dp[i] == two)
                a++;
            
            if(dp[i] == three)
                b++;
            
            if(dp[i] == five)
                c++;
        }
        
        return dp[n-1];
    }
};