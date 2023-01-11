class Solution {
public:
    
    int solve(int n){
        
        int sum = 0;
        
        while(n){
            sum += n%10;
            n/=10;
        }
        
        return sum;
    }
    
    int countEven(int num) {
        
        int digiSum = 0, ans = 0;
        
        for(int i = 1; i<=num; i++){
            digiSum = solve(i);
            
            if((digiSum&1) == 0)
                ans++;
        }
        
        return ans;
    }
};