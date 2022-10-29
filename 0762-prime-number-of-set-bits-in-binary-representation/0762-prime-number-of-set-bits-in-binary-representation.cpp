class Solution {
public:
    
    int count(int n){
        int ans = 0;
        
        while(n>0){
            if(n&1)
                ans++;
            
            n >>= 1;
        }
        
        return ans;
    }
    
    int prime(int n){
        if(n==1)
            return 0;
        
        for(int i = 2; i<=sqrt(n); i++){
            if(n%i == 0){
                return 0;
            }
        }
        return 1;
    }
    
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        
        for(int i = left ; i<=right; i++){
            int set = count(i);
            
            cout<<set;
            if(prime(set))
                ans++;
        }
        return ans;
    }
};