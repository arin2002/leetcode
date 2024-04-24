class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, ans = 1;
        
        if(n <= 1)
            return n;
        
        for(int i = 2; i<n; i++){
            ans = a+b+c;
            a = b;
            b = c;
            c = ans;
        }
        
        return ans;
    }
};