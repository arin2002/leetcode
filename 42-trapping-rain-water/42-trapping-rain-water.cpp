class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size(),ans=0;
        
        int l = 0,  r = n-1;
        
        int maxL = 0 , maxR = 0;
        while(l<=r){
            if(a[l] <= a[r]){
                if(a[l] >= maxL)
                    maxL = a[l];
                else
                    ans += maxL - a[l];
                
                l++;
            }
            else{
                if(a[r] >= maxR)
                    maxR = a[r];
                else
                    ans += maxR - a[r];
                
                r--;
            }
        }
        return ans;
    }
};