class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> v;
        int i=0, stepLength = 1, dir = 0, stepsTakenInCurrentLen = 0, counter = 0;
        while( i != rows*cols)
        {
            if(rStart >= 0 && cStart >=0 && rStart < rows && cStart < cols)
            {
                v.push_back({rStart, cStart});
                i++;
            }
            if(dir == 0)
                cStart++;
            else if(dir == 1)
                rStart++;
            else if(dir == 2)
                cStart--;
            else
                rStart--;
            counter++;
            if(stepLength == counter)
            {
                dir = (dir+1)%4;
                counter = 0;
                stepsTakenInCurrentLen = (stepsTakenInCurrentLen+1)%2;
                if(stepsTakenInCurrentLen == 0)
                    stepLength++;
            }
        }
        return v;
    }
};
