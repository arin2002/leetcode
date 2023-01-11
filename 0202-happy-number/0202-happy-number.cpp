class Solution {
public:
    
    long solve(long n){        
        long sum = 0;
        while(n != 0){
            long t = n%10;
            sum += (t*t);
            n /= 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        
        // cycle ban jayegi not happy walo mai 
        // unordered_set<long> ump;
        long fast = solve(n), slow = n;
        
        while(fast != 1){
            if(slow == fast)
                return 0;
            
            fast = solve(fast);
            fast = solve(fast);
            slow = solve(slow);
        }
        
        return 1;
    }
};