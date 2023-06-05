class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& nums) {
        int n = nums.size();
        double x1 = nums[0][0], y1 = nums[0][1];
        double x2 = nums[1][0], y2 = nums[1][1];
        
        double m = 0;
        if(x2-x1 != 0)
            m = (y2-y1)/(x2-x1);
        else
            m = INT_MAX;
        
        for(int i = 2; i<n; i++){
            double x1 = nums[i-1][0], y1 = nums[i-1][1];
            double x2 = nums[i][0], y2 = nums[i][1];
            
            double t = 0;
            if(x2-x1 != 0)
                t = (y2-y1)/(x2-x1);
            else
                t = INT_MAX;
            
            if(t!=m)
                return false;
        }
        
        return true;
    }
};