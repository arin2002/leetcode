class Solution {
public:
    int mySqrt(int x) {
        
        long long int i = 1, j = x;
        int ans = 0;
        while(i<=j)
        {
            long long mid = i+(j-i)/2;
            
            long long temp = mid * mid;
            
            if(temp == x)
                return mid;
            
            else if (temp <x){
                ans = mid;
                i = mid+1;
            }
            else
                j = mid -1;
        }
        
        return ans;
    }
};