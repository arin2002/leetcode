class Solution {
public:
    
    long solve(int n){
        
        long sum = 0;
        
        while(n){
            sum += n%10;
            n /= 10;
        }
        
        return sum;
    }
    
    
    int getLucky(string s, int k) {
        long long num = 0;
        
        for(auto it : s){
            long long n = it-'a'+1;
            
            if(n>=10){
                num += n%10;
                n/=10;
                num += n%10;
            }
            else{
                num += n;
            }
        }
        
        k--;
        while(k!=0){
            num = solve(num);
            k--;
        }
        
        return num;
    }
};