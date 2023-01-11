class Solution {
public:
    int countDigits(int num) {
        int temp = num, ans = 0;
        
        while(temp){
            
            int val = temp%10;
            
            if(num%val == 0)
                ans++;
            
            temp/=10;
        }
        
        return ans;
    }
};