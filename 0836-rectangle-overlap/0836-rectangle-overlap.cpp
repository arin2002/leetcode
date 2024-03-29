class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //for not overlapping on x-axis
        if(rec1[2]<=rec2[0] || rec2[2]<=rec1[0])
            return false;
        
        //for not overlapping on y-axis
        if(rec2[1]>=rec1[3] || rec1[1]>=rec2[3])
            return false;
        
        return true;
    }
};