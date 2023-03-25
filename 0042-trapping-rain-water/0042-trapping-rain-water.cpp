class Solution {
public:
    int trap(vector<int>& heights) {
        int i = 0, j = heights.size()-1, l_max = 0, r_max = 0;
        
        int ans = 0;
        while(i<=j){
            if(heights[i]<=heights[j]){
                if(heights[i]<l_max)
                    ans += (l_max-heights[i]);
                
                else
                    l_max = heights[i];
                
                i++;
            }
            else{
                if(heights[j] <= r_max)
                    ans += (r_max-heights[j]);
                
                else
                    r_max = heights[j];
                
                j--;
            }
        }
        
        return ans;
    }
};