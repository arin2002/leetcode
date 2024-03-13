class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n, sum = ((n)*(n+1))/2;
        
        while(l<=r){
            int mid = (l+r)/2;
            int lsum = ((mid)*(mid+1))/2, rsum = sum-lsum+mid;
            
            cout<<mid<<" ";
            if(lsum == rsum)
                return mid;
            
            else if(lsum<rsum)
                l = mid+1;
            else{
                r = mid-1;
            }
        }
        
        return -1;
    }
};