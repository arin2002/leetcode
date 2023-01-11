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
        unordered_set<long> ump;
        
        while(n != 1){
            if(ump.find(n) != ump.end())
                return 0;
            
            ump.insert(n);
            n = solve(n);
        }
        
        return 1;
    }
};