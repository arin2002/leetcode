class Solution {
public:
    int trailingZeroes(int n) {
        
        int count2 = 0, count5 = 0, ans = 0;
        for(int i = 1; i <= n; i++){
            int num = i;
            
            // if(num%10 == 0){
            //     ans += num/10;
            //     continue;
            // }
            
            if(num%2 == 0){
                while(num > 0 && num%2 == 0){
                    if(count5)
                        ans++;
                    else
                        count2++;
                    
                    num/=2;
                }
            }
            
            if(num%5 == 0){
                while(num>0 && num%5 == 0){
                    if(count2)
                        ans++;
                    
                    else
                        count5++;
                    
                    num/=5;
                }
            }
        }
        
        return ans;
    }
};