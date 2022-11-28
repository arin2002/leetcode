class Solution {
public:
    
    int f(int x){
        return (x*(x+1))/2;
    }
    
    int pivotInteger(int n) {
        int i = 1, j = n;
        
        int total = (n*(n+1))/2;
        
        while(i<=j){
            int mid = (i+j)/2;
            
            if(f(mid) == total-f(mid-1))
                return mid;
            
            if(f(mid)>total-f(mid-1))
                j = mid-1;
            else
                i = mid+1;
        }
        
        return -1;
    }
};
