class Solution {
public:
    
    int rev(int n){
        int ans = 0;
        while(n>0){
            ans = ans*10 + n%10;
            n/=10;
        }
        
        return ans;
    }
    
    
    bool sumOfNumberAndReverse(int num) {        
        for(int i = 0; i<100000; i++){
            if(i + rev(i) == num){
                return true;
            }
        }
        return false;
    }
};