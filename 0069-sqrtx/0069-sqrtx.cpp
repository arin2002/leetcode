class Solution {
public:
    int mySqrt(int x) {
        int i = 1, j = x;
        
        while(i<=j){
            int mid = i + (j-i)/2;
            
            if((x/mid) == mid){
                return mid;
            }
            
            else if((x/mid) > mid){
                i = mid+1;
            }
            else
                j = mid-1;
        }
        return i-1;
    }
};