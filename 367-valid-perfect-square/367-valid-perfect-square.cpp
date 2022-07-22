class Solution {
public:
    bool isPerfectSquare(int n) {
        
        if(n==1)
            return true;
        
        int i = 1, j = n/2;
        
        while(i<=j)
        {
            long long int mid = i+(j-i)/2;
            
            long long test = mid * mid;
            
            if(test == n)
                return true;
            
            else if(test < n)
                i = mid+1;
            else
                j = mid -1;
        }
        
        return false;
    }
};