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
    
    int prime(int x){
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
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