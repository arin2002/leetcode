class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long i = 0, j = sqrt(c);
        
        while(i<=j)
        {
            long long  a = i*i, b =j*j;
            long long  d = a+b;
            
            if(c == d)
                return true;
            
            else if(c < d)
                j--;
            else
                i++;
        }
        
        return false;
    }
};