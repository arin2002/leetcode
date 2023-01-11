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
    
    int addDigits(int num) {
        
        while(num>9){
            num = solve(num);
        }
        
        return num;
    }
};