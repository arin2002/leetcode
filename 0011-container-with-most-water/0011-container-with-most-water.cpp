class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        
        int area = 0, ans = 0;
        while(i<j){
            
            // l*b
            // ye hogi length mini kyuki jyda hui to overflow
            // hoga
            int l = min(height[i],height[j]);
            int b = j-i;
            area = l*b;
            
            ans = max(area,ans);
            
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        
        return ans;
    }
};