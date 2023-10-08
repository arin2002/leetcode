class Solution {
public:
    int man, nan;
    int t[501][501];
    
    int sol(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == man || j == nan)
            return -100000000; //send a large negative number. Don't send 0 because we can have -ve product as well. For example : {-1, -1}, {1, 1}, output should be -1.
        
        if(t[i][j] != -1e9)
            return t[i][j];
        
        int valu = nums1[i] * nums2[j];
        
        int take_i_j = sol(nums1, nums2, i+1, j+1) + valu;
        
        int take_i = sol(nums1, nums2, i, j+1);
        int take_j = sol(nums1, nums2, i+1, j);
        
        
        return t[i][j] = max({valu, take_i_j, take_i, take_j});
        
        
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        man = nums1.size();
        nan = nums2.size();
        
        for(int i = 0; i<501; i++) {
            for(int j = 0; j < 501; j++) {
                t[i][j] = -1e9;
            }
        }
        
        return sol(nums1, nums2, 0, 0);
    }
};