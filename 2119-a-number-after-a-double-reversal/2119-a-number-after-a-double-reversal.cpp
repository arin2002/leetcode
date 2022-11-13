class Solution {
public:
    
    bool f (int n){
        int digit = n%10;
        
        if(digit == 0)
            return false;
        
        return true;
    }
    
    bool isSameAfterReversals(int num) {
        if(num == 0)
            return 1;
        
        return f(num);
    }
};