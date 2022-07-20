// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int i = 1, j = n;
        
        int mini = 0;
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            if(isBadVersion(mid) == 1 )          
            {
                mini = mid;
                j = mid-1;
            }
            
            else if(isBadVersion(mid) == 0)
                i = mid+1;
        }
        
        return mini;
    }
};