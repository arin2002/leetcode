class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, n = height.size(), r = height.size()-1;
        int lmax = 0, rmax = 0, ans = 0;
        
        // logic is main try to use diagram
        while(l<=r){
            if(height[l]<height[r]){
                if(lmax>height[l]){
                    ans += lmax-height[l];
                }
                else{
                    lmax = height[l];
                }
                
                l++;
            }
            else{
                if(rmax>height[r]){
                    ans += rmax-height[r];
                }
                else{
                    rmax = height[r];
                }
                
                r--;
            }
        }
        
        return ans;
    }
};