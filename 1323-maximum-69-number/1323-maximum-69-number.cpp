class Solution {
public:
    int maximum69Number (int num) {
        int ind = -1;
        int add = 1;
        
        int n = num;
        while(n>0){
            int digit = n%10;
            
            if(digit == 6)
                ind = add;
            
            add*=10;
            n/=10;
        }
        
        if(ind == -1)
            return num;
        
        num = num + ind*3;
        return num;
    }
};